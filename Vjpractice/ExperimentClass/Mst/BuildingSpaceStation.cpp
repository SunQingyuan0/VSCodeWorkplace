#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue> 
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=205;
struct p{
	double x,y,z,r;
}a[N];
struct node{
	int u,v;
	double w;
	bool operator<(const node&a)const{
		return w<a.w;
	}
}e[N*N];
int s[N];
int find(int x){
	if(s[x]!=x) s[x]=find(s[x]);
	return s[x];
}
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		int k=0;
		for(int i=1;i<=n;i++) s[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
		for(int j=1;j<i;j++)
		{
			double dis=((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z));
			dis=sqrt(dis),dis-=(a[i].r+a[j].r);
			e[++k].u=i,e[k].v=j,e[k].w=dis;
		}
	}
	sort(e+1,e+1+k);
	int tot=0;
	double ans=0;
		for(int i=1;i<=k;i++){
			int fa=find(e[i].u),fb=find(e[i].v);
			if(fa==fb) continue;
			tot++;
			s[fb]=fa;
			if(e[i].w>0) ans+=e[i].w;
			if(tot==n-1) break;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
