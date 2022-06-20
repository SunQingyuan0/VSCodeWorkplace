/*
You are a member of the space station engineering team, and are assigned a task in the construction process of the station. You are expected to write a computer program to complete the task.
The space station is made up with a number of units, called cells. All cells are sphere-shaped, but their sizes are not necessarily uniform. Each cell is fixed at its predetermined position shortly after the station is successfully put into its orbit. It is quite strange that two cells may be touching each other, or even may be overlapping. In an extreme case, a cell may be totally enclosing another one. I do not know how such arrangements are possible.

All the cells must be connected, since crew members should be able to walk from any cell to any other cell. They can walk from a cell A to another cell B, if, (1) A and B are touching each other or overlapping, (2) A and B are connected by a `corridor', or (3) there is a cell C such that walking from A to C, and also from B to C are both possible. Note that the condition (3) should be interpreted transitively.

You are expected to design a configuration, namely, which pairs of cells are to be connected with corridors. There is some freedom in the corridor configuration. For example, if there are three cells A, B and C, not touching nor overlapping each other, at least three plans are possible in order to connect all three cells. The first is to build corridors A-B and A-C, the second B-C and B-A, the third C-A and C-B. The cost of building a corridor is proportional to its length. Therefore, you should choose a plan with the shortest total length of the corridors.

You can ignore the width of a corridor. A corridor is built between points on two cells' surfaces. It can be made arbitrarily long, but of course the shortest one is chosen. Even if two corridors A-B and C-D intersect in space, they are not considered to form a connection path between (for example) A and C. In other words, you may consider that two corridors never intersect.
Input
The input consists of multiple data sets. Each data set is given in the following format.

n
x1 y1 z1 r1
x2 y2 z2 r2
...
xn yn zn rn

The first line of a data set contains an integer n, which is the number of cells. n is positive, and does not exceed 100.

The following n lines are descriptions of cells. Four values in a line are x-, y- and z-coordinates of the center, and radius (called r in the rest of the problem) of the sphere, in this order. Each value is given by a decimal fraction, with 3 digits after the decimal point. Values are separated by a space character.

Each of x, y, z and r is positive and is less than 100.0.

The end of the input is indicated by a line containing a zero.
Output
For each data set, the shortest total length of the corridors should be printed, each in a separate line. The printed values should have 3 digits after the decimal point. They may not have an error greater than 0.001.

Note that if no corridors are necessary, that is, if all the cells are connected without corridors, the shortest total length of the corridors is 0.000.
Sample Input
3
10.000 10.000 50.000 10.000
40.000 10.000 50.000 10.000
40.000 40.000 50.000 10.000
2
30.000 30.000 30.000 20.000
40.000 40.000 40.000 20.000
5
5.729 15.143 3.996 25.837
6.013 14.372 4.818 10.671
80.115 63.292 84.477 15.120
64.095 80.924 70.029 14.881
39.472 85.116 71.369 5.553
0
Sample Output
20.000
0.000
73.834
*/
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