#include<cstdio>
#include<cstdlib>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define MAXLINE 1024
#define	SA	struct sockaddr
u_int Dg_send_recv(int, const void *, size_t, void *, size_t,
					 const SA *, int);

void dg_cli(FILE *fp, int sockfd, const SA *pservaddr, int servlen)
{
	u_int n;
	char sendline[MAXLINE], recvline[MAXLINE + 1];

	while (Fgets(sendline, MAXLINE, fp) != NULL)
	{

		n = Dg_send_recv(sockfd, sendline, strlen(sendline),
						 recvline, MAXLINE, pservaddr, servlen);

		recvline[n] = 0; /* null terminate */
		Fputs(recvline, stdout);
	}
}
