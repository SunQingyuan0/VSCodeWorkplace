/*Programmer Sasha is a student at MIPT (Moscow Institute of Physics and Technology) and he needs to make a laboratory work to pass his finals.

A laboratory unit is a plane with standard coordinate axes marked on it. Physicists from Moscow Institute of Physics and Technology charged the axes by large electric charges: axis X is positive and axis Y is negative.

Experienced laboratory worker marked n points with integer coordinates (xi, yi) on the plane and stopped the time. Sasha should use "atomic tweezers" to place elementary particles in these points. He has an unlimited number of electrons (negatively charged elementary particles) and protons (positively charged elementary particles). He can put either an electron or a proton at each marked point. As soon as all marked points are filled with particles, laboratory worker will turn on the time again and the particles will come in motion and after some time they will stabilize in equilibrium. The objective of the laboratory work is to arrange the particles in such a way, that the diameter of the resulting state (the maximum distance between the pairs of points of the set) is as small as possible.

Since Sasha is a programmer, he naively thinks that all the particles will simply "fall" into their projections on the corresponding axes: electrons will fall on axis X, while protons will fall on axis Y. As we are programmers too, we will consider the same model as Sasha. That is, a particle gets from point (x, y) to point (x, 0) if it is an electron and to point (0, y) if it is a proton.

As the laboratory has high background radiation and Sasha takes care of his laptop, he did not take it with him, and now he can't write a program that computes the minimum possible diameter of the resulting set. Therefore, you will have to do it for him.

Print a square of the minimum possible diameter of the set.

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of points marked on the plane.

Each of the next n lines contains two integers xi and yi ( - 108 ≤ xi, yi ≤ 108) — the coordinates of the i-th point. It is guaranteed that no two points coincide.

Output
Print a single integer — the square of the minimum possible diameter of the set.

Examples
Input
3
1 10
1 20
1 30
Output
0
Input
2
1 10
10 1
Output
2*/
#include <iostream>
#include <random>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <bitset>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<' ';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head
 
 
 
#ifdef ONLINE_JUDGE
const int N = 1e6+10;
#else
const int N = 111;
#endif
 
int n;
pii a[N];
int Lmin[N], Lmax[N], Rmin[N], Rmax[N];
 
ll sqr(ll x) {return x*x;}
ll ans = 1e18;
int chk(ll e) {
    if (ans<=e) return 1;
	int now = 1;
	ll ans = 1e18;
	REP(i,1,n) {
		if (a[i].x>0) break;
		while (now<n&&sqr(a[now+1].x-a[i].x)<=e&&abs(a[now+1].x)<=abs(a[i].x)) ++now;
		while (abs(a[now].x)>abs(a[i].x)) --now;
		int U = -1e9, D = 1e9;
		if (i>1) U=max(U,Lmax[i-1]),D=min(D,Lmin[i-1]);
		if (now<n) U=max(U,Rmax[now+1]),D=min(D,Rmin[now+1]);
		ans = min(ans, max(sqr(U-D),max(sqr(U),sqr(D))+max(sqr(a[i].x),sqr(a[now].x))));
	}
	now = n;
	PER(i,1,n) {
		if (a[i].x<0) break;
		while (now>1&&sqr(a[now-1].x-a[i].x)<=e&&abs(a[now-1].x)<=abs(a[i].x)) --now;
		while (abs(a[now].x)>abs(a[i].x)) ++now;
		int U = -1e9, D = 1e9;
		if (i<n) U=max(U,Rmax[i+1]),D=min(D,Rmin[i+1]);
		if (now>1) U=max(U,Lmax[now-1]),D=min(D,Lmin[now-1]);
		ans = min(ans, max(sqr(U-D),max(sqr(U),sqr(D))+max(sqr(a[i].x),sqr(a[now].x))));
	}
	return ans<=e;
}
 
int main() {
	scanf("%d", &n);
	REP(i,1,n) scanf("%d%d", &a[i].x,&a[i].y);
	sort(a+1,a+1+n);
	Lmin[1]=Lmax[1]=a[1].y;
	REP(i,2,n) { 
		Lmin[i]=min(Lmin[i-1],a[i].y);
		Lmax[i]=max(Lmax[i-1],a[i].y);
	}
	Rmin[n]=Rmax[n]=a[n].y;
	PER(i,1,n-1) {
		Rmin[i]=min(Rmin[i+1],a[i].y);
		Rmax[i]=max(Rmax[i+1],a[i].y);
	}
	ll l = 0, r = min(sqr(Lmin[n]-Lmax[n]),sqr(a[1].x-a[n].x));
	ans = r;
	while (l<=r) {
		if (chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n", ans);
}