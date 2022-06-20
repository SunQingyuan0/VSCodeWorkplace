#include<cstdio>
#include<cstdlib>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define MAXLINE 1024
#define	SA	struct sockaddr

void dg_echo(int sockfd, SA *pcliaddr, int clilen)
{
	int n;
	int len;
	char mesg[MAXLINE];

	for (;;)
	{
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		Sendto(sockfd, mesg, n, 0, pcliaddr, clilen);
	}
}
