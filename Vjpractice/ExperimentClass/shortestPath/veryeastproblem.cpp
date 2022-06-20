/*
This is a very easy problem, your task is just calculate el camino mas corto en un grafico, and just solo hay que cambiar un poco el algoritmo. If you do not understand a word of this paragraph, just move on.
The Nya graph is an undirected graph with "layers". Each node in the graph belongs to a layer, there are N nodes in total.
You can move from any node in layer x to any node in layer x + 1, with cost C, since the roads are bi-directional, moving from layer x + 1 to layer x is also allowed with the same cost.
Besides, there are M extra edges, each connecting a pair of node u and v, with cost w.
Help us calculate the shortest path from node 1 to node N.
Input
The first line has a number T (T <= 20) , indicating the number of test cases.
For each test case, first line has three numbers N, M (0 <= N, M <= 105) and C(1 <= C <= 103), which is the number of nodes, the number of extra edges and cost of moving between adjacent layers.
The second line has N numbers li (1 <= li <= N), which is the layer of ith node belong to.
Then come N lines each with 3 numbers, u, v (1 <= u, v < =N, u <> v) and w (1 <= w <= 104), which means there is an extra edge, connecting a pair of node u and v, with cost w.
Output
For test case X, output "Case #X: " first, then output the minimum cost moving from node 1 to node N.
If there are no solutions, output -1.
Sample Input
2
3 3 3
1 3 2
1 2 1
2 3 1
1 3 3

3 3 3
1 3 2
1 2 2
2 3 2
1 3 4
Sample Output
Case #1: 2
Case #2: 3
*/
#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=200005;
const int maxm=800010;
struct Edge
{
    int to,next,w;
} edge[maxm];
int tot;
int head[maxn];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int d[maxn*2];
bool vis[maxn*2];
struct node
{
    int u,w;
    node(int u,int d):u(u),w(d) {}
};
bool operator < (node a,node b)
{
    return a.w > b.w;
}
void  dijk(int s,int n)
{
    memset(vis,0,sizeof(vis));
    priority_queue<node> que;
    for(int i=0; i<=n; i++) d[i]=INF;
    d[s]=0;
    que.push(node(s,0));
    while(!que.empty())
    {
        node tmp = que.top();
        que.pop();
        int u=tmp.u;
        if(vis[u]) continue;
        vis[u]=true;
        for(int e=head[u]; e!=-1; e=edge[e].next)
        {
            int v=edge[e].to,w=edge[e].w;
            if(vis[v]) continue;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                que.push(node(v,d[v]));
            }
        }
    }
}
int a[maxn*2];
int main()
{
  
    int T,n,m,t,u,v,w;
    int cases=1;
    scanf("%d",&T);

    while(T--)
    {
        init();
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
      
        scanf("%d%d%d",&n,&m,&t);
        int val;
        for(int i=1;i<=n;i++)
            {
               
                scanf("%d",&val);
                a[i]=val;//a[i]
                vis[val]=1;
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]+1]&&a[i]<n)
          
                        addedge(i,a[i]+n+1,t);
                }
                else if(a[i]==n)
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]-1]&&a[i]>1)
                        addedge(i,a[i]+n-1,t);
                }
                else
                {
                    addedge(a[i]+n,i,0);
                    if(vis[a[i]+1]&&a[i]<n)
                        addedge(i,a[i]+n+1,t);
                      if(vis[a[i]-1]&&a[i]>1)
                        addedge(i,a[i]+n-1,t);
                }
            }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dijk(1,n*2);
        if(d[n]==INF)
            d[n]=-1;
      
        printf("Case #");
        printf("%d",cases++);
        printf(": ");
        printf("%d\n",d[n]);

    }
    return 0;
}