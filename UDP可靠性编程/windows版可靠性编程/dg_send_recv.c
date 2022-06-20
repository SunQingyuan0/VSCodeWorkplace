
#include "unprtt.h"
#include <setjmp.h>
#include <cstdio>
#include <cstdlib>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define MAXLINE 1024
#define SA struct sockaddr
#include <signal.h>
#define RTT_DEBUG
#define _NSIG_WORDS 2
#define	SIGALRM		14	/* Alarm clock (POSIX).  */
typedef struct
{
	unsigned long sig[_NSIG_WORDS];
} sigset_t;

#ifdef _JBTYPE
typedef _JBTYPE sigjmp_buf[_JBLEN+1+((sizeof (_JBTYPE) + sizeof (sigset_t) - 1)
                     /sizeof (_JBTYPE))];
#else
typedef int sigjmp_buf[_JBLEN+1+(sizeof (sigset_t)/sizeof (int))];
#endif
struct iovec {                    /* Scatter/gather arrayitems */
      void *iov_base;              /*Starting address */
      size_t iov_len;               /* Number of bytes to transfer*/
  };
   /* iov_base: iov_base指向数据包缓冲区，即参数buff，iov_len是buff的长度。msghdr中允许一次传递多个buff，
     以数组的形式组织在 msg_iov中，msg_iovlen就记录数组的长度（即有多少个buff）
   */
  struct msghdr {
      void         *msg_name;       /* optional address */
      int     msg_namelen;    /* size of address */
      struct iovec *msg_iov;        /* scatter/gather array */
      size_t        msg_iovlen;     /* # elements in msg_iov */
      void         *msg_control;    /* ancillary data, see below */
      size_t        msg_controllen; /* ancillary databuffer len */
      int           msg_flags;      /* flags on received message */
  };
  /* msg_name：数据的目的地址，网络包指向sockaddr_in, netlink则指向sockaddr_nl;
     msg_namelen: msg_name 所代表的地址长度
     msg_iov: 指向的是缓冲区数组
     msg_iovlen: 缓冲区数组长度
     msg_control: 辅助数据，控制信息(发送任何的控制信息)
     msg_controllen: 辅助信息长度
     msg_flags: 消息标识
  */
static struct rtt_info rttinfo;
static int rttinit = 0;
static struct msghdr msgsend, msgrecv; /* assumed init to 0 */
static struct hdr
{
	u_int seq; /* sequence # */
	u_int ts;  /* timestamp when sent */
} sendhdr, recvhdr;

static void sig_alrm(int signo);
static sigjmp_buf jmpbuf;

u_int dg_send_recv(int fd, const void *outbuff, size_t outbytes,
				   void *inbuff, size_t inbytes,
				   const SA *destaddr, int destlen)
{
	u_int n;
	struct iovec iovsend[2], iovrecv[2];

	if (rttinit == 0)
	{
		rtt_init(&rttinfo); /* first time we're called 初始化RTO*/
		rttinit = 1;
		rtt_d_flag = 1;
	}

	sendhdr.seq++;
	msgsend.msg_name = destaddr;
	msgsend.msg_namelen = destlen;
	msgsend.msg_iov = iovsend;
	msgsend.msg_iovlen = 2;
	iovsend[0].iov_base = &sendhdr;
	iovsend[0].iov_len = sizeof(struct hdr);
	iovsend[1].iov_base = outbuff;
	iovsend[1].iov_len = outbytes;

	msgrecv.msg_name = NULL;
	msgrecv.msg_namelen = 0;
	msgrecv.msg_iov = iovrecv;
	msgrecv.msg_iovlen = 2;
	iovrecv[0].iov_base = &recvhdr;
	iovrecv[0].iov_len = sizeof(struct hdr);
	iovrecv[1].iov_base = inbuff;
	iovrecv[1].iov_len = inbytes;
	/* end dgsendrecv1 */

	/* include dgsendrecv2 */
	Signal(SIGALRM, sig_alrm);
	rtt_newpack(&rttinfo); /* initialize for this packet 重传次数置0*/

sendagain:
#ifdef RTT_DEBUG
	fprintf(stderr, "send %4d: ", sendhdr.seq);
#endif
	sendhdr.ts = rtt_ts(&rttinfo); /*获取当前时间戳并把它存入将安置在用户数据之间的hdr结构中*/
	Sendmsg(fd, &msgsend, 0);

	alarm(rtt_start(&rttinfo)); /* calc timeout value & start timer rtt_start以秒位单位返回当前RTO*/
#ifdef RTT_DEBUG
	rtt_debug(&rttinfo);
#endif

	if (sigsetjmp(jmpbuf, 1) != 0)
	{ /* 定时器期满，sigsetjmp由长跳转返回1*/
		if (rtt_timeout(&rttinfo) < 0)
		{ /*rtt_timeout进行指数回退，如果重传次数大于最大值，返回-1*/
			err_msg("dg_send_recv: no response from server, giving up");
			rttinit = 0; /* reinit in case we're called again */
			errno = ETIMEDOUT;
			return (-1);
		}
#ifdef RTT_DEBUG
		err_msg("dg_send_recv: timeout, retransmitting");
#endif
		goto sendagain;
	}

	do
	{
		n = Recvmsg(fd, &msgrecv, 0);
#ifdef RTT_DEBUG
		fprintf(stderr, "recv %4d\n", recvhdr.seq);
#endif
	} while (n < sizeof(struct hdr) || recvhdr.seq != sendhdr.seq);

	alarm(0);										   /* stop SIGALRM timer 收到期待的应答，关闭尚未期满的alarm*/
													   /* 4calculate & store new RTT estimator values */
	rtt_stop(&rttinfo, rtt_ts(&rttinfo) - recvhdr.ts); /*收到一个应答，更新RTT，并重新计算RTO*/

	return (n - sizeof(struct hdr)); /* return size of received datagram */
}

static void
sig_alrm(int signo)
{
	siglongjmp(jmpbuf, 1);
}
/* end dgsendrecv2 */

u_int Dg_send_recv(int fd, const void *outbuff, size_t outbytes,
				   void *inbuff, size_t inbytes,
				   const SA *destaddr, int destlen)
{
	u_int n;

	n = dg_send_recv(fd, outbuff, outbytes, inbuff, inbytes,
					 destaddr, destlen);
	if (n < 0)
		err_quit("dg_send_recv error");

	return (n);
}
