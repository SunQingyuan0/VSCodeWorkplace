#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 200010
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
    int q;
    scanf("%d",&q);
   while (q--)
   {
       int n;
       scanf("%d",&n);
       int sum=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=i+1;j<=n;j++)
           {
               if(gcd(j,i)==(i^j))sum++;
           }
       }
       printf("%d\n",sum);
   }
   
}