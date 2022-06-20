#include<iostream>
#include<cstdio>
using namespace std;
 
const int MAXN=5000+100;
int per[3][MAXN];
 
int min(int a,int b)
{
	return a<b?a:b;
}
 
int main()
{
	int n,cnt1,cnt2,cnt3,tmp,count,i;
	while(~scanf("%d",&n))
	{
		cnt1=0,cnt2=0,cnt3=0;
		i=1;
		while(i<=n)
		{
			scanf("%d",&tmp);
			switch(tmp)
			{
			case 1:per[0][cnt1++]=i;break;
			case 2:per[1][cnt2++]=i;break;
			case 3:per[2][cnt3++]=i;break;
			}
			++i;
		}	
		count=min(min(cnt1,cnt2),cnt3);	
		printf("%d\n",count);
		for(int i=0;i<count;i++)
		{
			printf("%d %d %d\n",per[0][i],per[1][i],per[2][i]);
		}
	}
	return 0;
}