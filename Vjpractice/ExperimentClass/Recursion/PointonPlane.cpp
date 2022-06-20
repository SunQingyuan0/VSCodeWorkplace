/*On a plane are n points (xi, yi) with integer coordinates between 0 and 106. The distance between the two points with numbers a and b is said to be the following value:  (the distance calculated by such formula is called Manhattan distance).

We call a hamiltonian path to be some permutation pi of numbers from 1 to n. We say that the length of this path is value .

Find some hamiltonian path with a length of no more than 25 × 108. Note that you do not have to minimize the path length.

Input
The first line contains integer n (1 ≤ n ≤ 106).

The i + 1-th line contains the coordinates of the i-th point: xi and yi (0 ≤ xi, yi ≤ 106).

It is guaranteed that no two points coincide.

Output
Print the permutation of numbers pi from 1 to n — the sought Hamiltonian path. The permutation must meet the inequality .

If there are multiple possible answers, print any of them.

It is guaranteed that the answer exists.

Examples
Input
5
0 7
8 10
3 4
5 0
9 12
Output
4 3 1 2 5 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 1000010
inline char gc(){
    static char buf[1<<16],*S,*T;
    if(S==T){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x*f;
}
int n;
struct point{
    int x,y,id;
}P[N];
inline bool cmp(point a,point b){return a.x<b.x;}
inline bool cmp1(point a,point b){return a.y<b.y;}
inline bool cmp2(point a,point b){return a.y>b.y;}
int main(){
//  freopen("a.in","r",stdin);
    n=read();
    for(int i=1;i<=n;++i) P[i].x=read(),P[i].y=read(),P[i].id=i;
    sort(P+1,P+n+1,cmp);
    for(int i=1,now=1;i<=n;++i,++now){
        int last=i;
        while(last<=n&&P[last].x<=now*1000) ++last;
        if(now&1) sort(P+i,P+last,cmp1);
        else sort(P+i,P+last,cmp2);
        for(int j=i;j<last;++j) printf("%d ",P[j].id);i=last-1;
    }return 0;
}