/*One day , Kiki wants to visit one of her friends. As she is liable to carsickness , she wants to arrive at her friend’s home as soon as possible . Now give you a map of the city’s traffic route, and the stations which are near Kiki’s home so that she can take. You may suppose Kiki can change the bus at any station. Please find out the least time Kiki needs to spend. To make it easy, if the city have n bus stations ,the stations will been expressed as an integer 1,2,3…n.
Input
There are several test cases.
Each case begins with three integers n, m and s,(n<1000,m<20000,1=<s<=n) n stands for the number of bus stations in this city and m stands for the number of directed ways between bus stations .(Maybe there are several ways between two bus stations .) s stands for the bus station that near Kiki’s friend’s home.
Then follow m lines ,each line contains three integers p , q , t (0<t<=1000). means from station p to station q there is a way and it will costs t minutes .
Then a line with an integer w(0<w<n), means the number of stations Kiki can take at the beginning. Then follows w integers stands for these stations.
Output
The output contains one line for each data set : the least time Kiki needs to spend ,if it’s impossible to find such a route ,just output “-1”.
Sample Input
5 8 5
1 2 2
1 5 3
1 3 4
2 4 7
2 5 6
2 3 5
3 5 1
4 5 1
2
2 3
4 3 4
1 2 3
1 3 4
2 3 2
1
1
Sample Output
1
-1*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define MaxInt 0x3f3f3f3f
using namespace std;
int Map[1005][1005];
int vis[1005];
int low[1005];
int p[1005];
int n,m,s;
int k;
void work()
{
    int pos = 0,Min;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i <= n; i++)
        low[i] = Map[pos][i];
    vis[pos] = 1;
    for(int i = 0; i < n; i++)
    {
 
        Min = MaxInt;
        for(int j = 0; j <= n; j++)
            if(!vis[j] && low[j] < Min)
            {
                pos = j;
                Min = low[j];
            }
        if(Min == MaxInt)
            break;
        vis[pos] = 1;
        for(int j = 0; j <= n; j++)
            if(!vis[j] && low[j] > low[pos]+Map[pos][j])
                low[j] = low[pos]+Map[pos][j];
    }
    if(low[s] < MaxInt)
        printf("%d\n",low[s]);
    else
        printf("-1\n");
}
 
int main()
{
    int a,b,c;
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        for(int i = 0; i <= n; i++)
        {
            Map[i][i] = 0;
            for(int j = 0; j <= n; j++)
                Map[i][j] = MaxInt;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(Map[a][b] > c)
                Map[a][b]=c;
        }
        int all,x;
        scanf("%d",&all);
        for(int i = 1; i <= all; i++){    
            scanf("%d",&x);
            Map[0][x] = 0;
        }
        work();
    }
    return 0;
}