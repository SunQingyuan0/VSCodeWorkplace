/*During the kindergarten days, flymouse was the monitor of his class. Occasionally the head-teacher brought the kids of flymouse’s class a large bag of candies and had flymouse distribute them. All the kids loved candies very much and often compared the numbers of candies they got with others. A kid A could had the idea that though it might be the case that another kid B was better than him in some aspect and therefore had a reason for deserving more candies than he did, he should never get a certain number of candies fewer than B did no matter how many candies he actually got, otherwise he would feel dissatisfied and go to the head-teacher to complain about flymouse’s biased distribution.

snoopy shared class with flymouse at that time. flymouse always compared the number of his candies with that of snoopy’s. He wanted to make the difference between the numbers as large as possible while keeping every kid satisfied. Now he had just got another bag of candies from the head-teacher, what was the largest difference he could make out of it?

Input
The input contains a single test cases. The test cases starts with a line with two integers N and M not exceeding 30 000 and 150 000 respectively. N is the number of kids in the class and the kids were numbered 1 through N. snoopy and flymouse were always numbered 1 and N. Then follow M lines each holding three integers A, B and c in order, meaning that kid A believed that kid B should never get over c candies more than he did.

Output
Output one line with only the largest difference desired. The difference is guaranteed to be finite.

Sample Input
2 2
1 2 5
2 1 4
Sample Output
5*/
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
    memset(Dis,0x3f,N*sizeof(int));
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
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        Init();
        Input(n,m);
        int ans=Dijkstra(n,m);
        printf("%d\n",ans);
    }
    
}