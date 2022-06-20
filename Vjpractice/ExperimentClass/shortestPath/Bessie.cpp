/*Bessie is out in the field and wants to get back to the barn to get as much sleep as possible before Farmer John wakes her for the morning milking. Bessie needs her beauty sleep, so she wants to get back as quickly as possible.

Farmer John's field has N (2 <= N <= 1000) landmarks in it, uniquely numbered 1..N. Landmark 1 is the barn; the apple tree grove in which Bessie stands all day is landmark N. Cows travel in the field using T (1 <= T <= 2000) bidirectional cow-trails of various lengths between the landmarks. Bessie is not confident of her navigation ability, so she always stays on a trail from its start to its end once she starts it.

Given the trails between the landmarks, determine the minimum distance Bessie must walk to get back to the barn. It is guaranteed that some such route exists.
Input
* Line 1: Two integers: T and N

* Lines 2..T+1: Each line describes a trail as three space-separated integers. The first two integers are the landmarks between which the trail travels. The third integer is the length of the trail, range 1..100.
Output
* Line 1: A single integer, the minimum distance that Bessie must travel to get from landmark N to landmark 1.
Sample Input
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
Sample Output
90*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define N 200010
typedef pair<int,int> Unit;
struct Node
{
    int v;
    int w;
};
Node GList[N];
int Dis[N];
int Head[N];
int Next[N];
int visit[N];
void Init()
{
    memset(Head,-1,N*sizeof(int));
    memset(Dis,0x3f3f,N*sizeof(int));
    memset(visit,0,N*sizeof(int));
    memset(Next,-1,N*sizeof(int));
    memset(GList,0,N*sizeof(Node));
}
void Input(int n,int m)
{
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        GList[cnt].v=v;
        GList[cnt].w=w;
        Next[cnt]=Head[u];
        Head[u]=cnt++;
        GList[cnt].v=u;
        GList[cnt].w=w;
        Next[cnt]=Head[v];
        Head[v]=cnt++;
    }
}
int Dijkstra(int n,int m)
{
    priority_queue<Unit,vector<Unit>,greater<Unit> > Que;
    Que.push(Unit(0,1));
    Dis[1]=0;
    while (!Que.empty())
    {
        int Now=Que.top().second;
        Que.pop();
        if(visit[Now])continue;
        visit[Now]=1;
        for(int i=Head[Now];i!=-1;i=Next[i])
        {
            int p=GList[i].v;
            int cost=GList[i].w;
            if(!visit[p]&&Dis[p]>Dis[Now]+cost)
            {
                Dis[p]=Dis[Now]+cost;
                Que.push(Unit(Dis[p],p));
            }
        }
    }
    return Dis[n];
}
int main()
{
    int n,m;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        Init();
        Input(n,m);
        int ans=Dijkstra(n,m);
        printf("%d\n",ans);
    }
}