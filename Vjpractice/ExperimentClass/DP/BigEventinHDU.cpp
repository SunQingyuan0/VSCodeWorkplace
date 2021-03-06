/*Nowadays, we all know that Computer College is the biggest department in HDU. But, maybe you don't know that Computer College had ever been split into Computer College and Software College in 2002.
The splitting is absolutely a big event in HDU! At the same time, it is a trouble thing too. All facilities must go halves. First, all facilities are assessed, and two facilities are thought to be same if they have the same value. It is assumed that there is N (0<N<1000) kinds of facilities (different value, different kinds).
Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 50 -- the total number of different facilities). The next N lines contain an integer V (0<V<=50 --value of facility) and an integer M (0<M<=100 --corresponding number of the facilities) each. You can assume that all V are different.
A test case starting with a negative integer terminates input and this test case is not to be processed.
Output
For each case, print one line containing two integers A and B which denote the value of Computer College and Software College will get respectively. A and B should be as equal as possible. At the same time, you should guarantee that A is not less than B.
Sample Input
2
10 1
20 1
3
10 1 
20 2
30 1
-1
Sample Output
20 10
40 40*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[5005],dp[300000];
int main()
{
	int sum,n,v,m,tot;
	while(~scanf("%d",&n)&&n>0)
	{
		tot=0;
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&v,&m);
			for(int j=0;j<m;j++)
			{
				a[++tot]=v;
				sum+=v;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=tot;i++)
			for(int j=sum/2;j>=a[i];j--)
			{
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
			int a=dp[sum/2];
			int b=sum-a;
			if(a<b)
				swap(a,b);
			printf("%d %d\n",a,b);
 
	}
	return 0;
}