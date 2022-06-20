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
        // if(second==n+1)
        // {
        //     if(Dis[second]-Dis[first]<mid)sum++;
        //     break;
        // }
    }
    if(sum>m)
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