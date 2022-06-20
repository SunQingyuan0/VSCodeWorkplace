/*One day Sasha visited the farmer 2D and his famous magnetic farm. On this farm, the crop grows due to the influence of a special magnetic field. Maintaining of the magnetic field is provided by n machines, and the power of the i-th machine is ai.

This year 2D decided to cultivate a new culture, but what exactly he didn't say. For the successful growth of the new culture, it is necessary to slightly change the powers of the machines. 2D can at most once choose an arbitrary integer x, then choose one machine and reduce the power of its machine by x times, and at the same time increase the power of one another machine by x times (powers of all the machines must stay positive integers). Note that he may not do that if he wants. More formally, 2D can choose two such indices i and j, and one integer x such that x is a divisor of ai, and change powers as following: ai=aix, aj=aj⋅x
Sasha is very curious, that's why he wants to calculate the minimum total power the farmer can reach. There are too many machines, and Sasha can't cope with computations, help him!
The first line contains one integer n (2≤n≤5⋅104) — the number of machines.

The second line contains n integers a1,a2,…,an (1≤ai≤100) — the powers of the machines.
Examples
Input
5
1 2 3 4 5
Output
14
Input
4
4 2 4 4
Output
14
Input
5
2 4 2 3 7
Output
18*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int Data[110];
        int sum=0;
        memset(Data,0,110*sizeof(int));
        int Min=101;
        for(int i=0;i<n;i++)
        {
            int temp;
            scanf("%d",&temp);
            sum+=temp;
            if(temp<Min)Min=temp;
            Data[temp]++;
        }
        int maxC=0;
        for(int i=100;i>0;i--)
        {
            for(int j=1;j<=i;j++)
            {
                if(Data[i]>=1)
                {
                    if(i%j==0)
                    {
                        maxC=max(maxC,Min+i-Min*j-i/j);
                    }
                }     
            }
        }
        sum-=maxC;
        printf("%d\n",sum);
    }
}
