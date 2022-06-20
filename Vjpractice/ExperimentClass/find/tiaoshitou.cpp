/*一年一度“跳石头”比赛又要开始了！

这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 
N
 块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。

为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多从起点和终点之间移走 
M
 块岩石（不能移走起点和终点的岩石）。
 Sample Input
 25 5 2
2
11
14
17
21
Sample Output
4*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 51000
typedef long long ll;
int Dis[N];
bool check(ll mid,ll n,ll m)
{
    ll first=0,second=1;
    ll sum=0;
    while (second<=n+1)
    {
        if(Dis[second]-Dis[first]>=mid)
        {
            first=second;
            second=second+1;
        }
        else
        {
            sum++;
            second++;
        }
        if(second==n+1)
        {
            if(Dis[second]-Dis[first]<mid)sum++;
            break;
        }
    }
    if(sum>=m)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    ll l,n,m;
    while (scanf("%lld%lld%lld",&l,&n,&m)!=EOF)
    {
        memset(Dis,0,N*sizeof(int));
        for(ll i=1;i<=n;i++)
        scanf("%lld",&Dis[i]);
        Dis[n+1]=l;
        ll low=0,r=l;
        ll ans=0;
        while (low<=r)
        {
            ll mid=(low+r)/2;
            if(check(mid,n,m))
            {
                r=mid-1;
            }
            else
            {
                low=mid+1;
                ans=mid;
            }  
        }
        printf("%d\n",ans);
    }
    
}