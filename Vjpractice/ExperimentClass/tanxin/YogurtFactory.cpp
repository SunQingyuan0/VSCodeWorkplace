/*The cows have purchased a yogurt factory that makes world-famous Yucky Yogurt. Over the next N (1 <= N <= 10,000) weeks, the price of milk and labor will fluctuate weekly such that it will cost the company C_i (1 <= C_i <= 5,000) cents to produce one unit of yogurt in week i. Yucky's factory, being well-designed, can produce arbitrarily many units of yogurt each week.

Yucky Yogurt owns a warehouse that can store unused yogurt at a constant fee of S (1 <= S <= 100) cents per unit of yogurt per week. Fortuitously, yogurt does not spoil. Yucky Yogurt's warehouse is enormous, so it can hold arbitrarily many units of yogurt.

Yucky wants to find a way to make weekly deliveries of Y_i (0 <= Y_i <= 10,000) units of yogurt to its clientele (Y_i is the delivery quantity in week i). Help Yucky minimize its costs over the entire N-week period. Yogurt produced in week i, as well as any yogurt already in storage, can be used to meet Yucky's demand for that week.
* Line 1: Two space-separated integers, N and S.

* Lines 2..N+1: Line i+1 contains two space-separated integers: C_i and Y_i.
* Line 1: Line 1 contains a single integer: the minimum total cost to satisfy the yogurt schedule. Note that the total might be too large for a 32-bit integer.
Sample Input
4 5
88 200
89 400
97 300
91 500
Sample Output
126900
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 10010
int cost[N];
int yogurt[N];
int main()
{
    int n,s;
    while (scanf("%d%d",&n,&s)!=EOF)
    {
        memset(cost,0,N*sizeof(int));
        memset(yogurt,0,sizeof(int)*N);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&cost[i],&yogurt[i]);
        }
        int mincost=cost[0];
        long long sum=cost[0]*yogurt[0];
        for(int i=1;i<n;i++)
        {
            if(cost[i]<mincost+s)
            {
                sum+=cost[i]*yogurt[i];
                mincost=cost[i];
            }
            else
            {
                sum+=(mincost+s)*yogurt[i];
                mincost+=s;
            }
        }
        printf("%lld\n",sum);
    } 
}