/*Freddy Frog is sitting on a stone in the middle of a lake. Suddenly he notices Fiona Frog who is sitting on another stone. He plans to visit her, but since the water is dirty and full of tourists' sunscreen, he wants to avoid swimming and instead reach her by jumping.
Unfortunately Fiona's stone is out of his jump range. Therefore Freddy considers to use other stones as intermediate stops and reach her by a sequence of several small jumps.
To execute a given sequence of jumps, a frog's jump range obviously must be at least as long as the longest jump occuring in the sequence.
The frog distance (humans also call it minimax distance) between two stones therefore is defined as the minimum necessary jump range over all possible paths between the two stones.

You are given the coordinates of Freddy's stone, Fiona's stone and all other stones in the lake. Your job is to compute the frog distance between Freddy's and Fiona's stone.
Input
The input will contain one or more test cases. The first line of each test case will contain the number of stones n (2<=n<=200). The next n lines each contain two integers xi,yi (0 <= xi,yi <= 1000) representing the coordinates of stone #i. Stone #1 is Freddy's stone, stone #2 is Fiona's stone, the other n-2 stones are unoccupied. There's a blank line following each test case. Input is terminated by a value of zero (0) for n.
Output
For each test case, print a line saying "Scenario #x" and a line saying "Frog Distance = y" where x is replaced by the test case number (they are numbered from 1) and y is replaced by the appropriate real number, printed to three decimals. Put a blank line after each test case, even after the last one.
Sample Input
2
0 0
3 4

3
17 4
19 4
18 5

0
Sample Output
Scenario #1
Frog Distance = 5.000

Scenario #2
Frog Distance = 1.414*/
#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 300;
double map[maxn][maxn];
int n;
int x[maxn],y[maxn];
int visited[maxn];
double dis[maxn];
void Dijkstra(int s)
{
	memset(visited,0,sizeof(visited));
	for(int i = 1;i<=n;i++)
	    dis[i]=INF;
	dis[s]=0;
	for(int i = 1;i<=n-1;i++)
	{
		int minn=INF,k;
		for(int j = 1;j<=n;j++)
			if(!visited[j]&&minn>dis[j])
				minn=dis[k=j];
		visited[k]=1;
		for(int j = 1;j<=n;j++) 
		   dis[j]=min(dis[j],max(dis[k],map[k][j]));
	}
}
int main(int argc, char** argv) {
	int cas=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		printf("Scenario #%d\n",++cas);
		for(int i = 1;i<=n;i++)
		    scanf("%d %d",&x[i],&y[i]);
		for(int i = 1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        map[i][j]=map[j][i]=sqrt(double(x[i]-x[j])*(x[i]-x[j])+double(y[i]-y[j])*(y[i]-y[j]));
		Dijkstra(1);
		printf("Frog Distance = %.3f\n\n",dis[2]);
	}
	return 0;
}