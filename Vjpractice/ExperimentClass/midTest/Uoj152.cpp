/*
picks 博士乘上时光机器，打算回到 2012 年化身马猴烧酒阻止金星凌日，挽救世风日下的 OI 界于水火之中。

但是不幸的是，时光机器出现了一些特殊的故障，picks 博士被传送到了一个未知的时空。为了修理时光机器，他必须要得到一种叫做巴拉拉能量的能源。经过调查，他发现在这个时空中存在着一个被当地人称为魔仙堡的领域，从生活在那儿的小魔仙那里就可以得到足够的巴拉拉能量。

然而在那个时空中，存在着一股强大的势力与善良的小魔仙们敌对——那就是邪恶的黑魔仙们。巴拉拉能量是不能被黑魔仙得到的，否则就会产生严重的后果。为了检验 picks 博士是否是黑魔仙派来窃取巴拉拉能量的奸细，睿智的魔仙女王给 picks 博士出了一道题：

我现在使用巴拉拉能量造了三根柱子（编号分别为 1 到 3）以及 n 块颜色不同的圆盘（编号为 1 到 n）。最开始我给定一个 1 到 n 的排列 A，我会用巴拉拉能量把这些圆盘放到编号为 1 的柱子上，使得从上到下第 i 块圆盘的编号是 Ai。

接着你可以进行若干次操作，每一次操作用两个整数 a,b （1≤a,b≤3,a≠b） 来描述，表示这次操作你将会把地 a 根柱子最上面的圆盘取出，并放到第 b 根柱子上去（如果当前第 a 根柱子上不存在圆盘，这次操作将会被小魔仙们忽略）。最终你要使得这 n 块圆盘在同一根柱子上，且从上到下编号依次递增（最终状态下所有圆盘可以在任意一根柱子上）。

小魔仙们虽然善良，但是他们的耐心并不是无限的，所以你必须在 106 次操作内完成任务。

输入格式
第一行一个正整数 n。

第二行是一个 1 到 n 的排列 A，相邻数字之间恰有一个空格隔开。

输出格式
第一行输出一个整数 K（0≤K≤106）。

接下来 K 行每行两个整数 ai,bi，按照顺序依次描述你的每一次操作。

如果有多种方案，输出任意一种即可。

样例一
input
3
2 1 3

output
4
1 3
1 2
3 1
2 1

explanation
最开始三根柱子上的圆盘状态分别为(2,1,3),(),()。

第一次操作后圆盘状态为(1,3),(),(2)
第二次操作后圆盘状态为(3),(1),(2)
第三次操作后圆盘状态为(2,3),(1),()
第四次操作后圆盘状态为(1,2,3),(),()
在所有操作结束后，圆盘都在第一根柱子上且从上到下编号依次递增。

样例二
见样例数据下载。

限制与约定
测试点编号	n 的规模
1	n≤10
2
3
4	n≤500
5
6
7	n≤10000
8
9
10
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define maxn 1000500
#define ll long long
#define inf int(1e9)
using namespace std;
int ansx[maxn],ansy[maxn],a[3][maxn],N[3];
int tot;
int read(){
    int x=0,f=1; char ch=getchar();
    while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar();}
    while (isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void move(int x,int y){
    ansx[++tot]=x+1,ansy[tot]=y+1;
    a[y][++N[y]]=a[x][N[x]--];
}
void dfs(int x,int l,int r,int dir){
    if (l==r) return;
    if (r-l<=1){
        if ((dir==0&&a[x][N[x]-1]<a[x][N[x]])||(dir==1&&a[x][N[x]-1]>a[x][N[x]])){
            move(x,(x+1)%3);
            move(x,(x+2)%3);
            move((x+1)%3,x);
            move((x+2)%3,x);
        }
        return;
    }
    int mid=(l+r)/2; int y=(x+1)%3,z=(x+2)%3;
    rep(i,l,r) if (a[x][N[x]]<=mid) move(x,y); else move(x,z);
    dfs(y,l,mid,1-dir);
    dfs(z,mid+1,r,1-dir);
    if (dir==0){
        down(i,r,mid+1) move(z,x);
        down(i,mid,l) move(y,x);     
    }
    else {
        rep(i,l,mid) move(y,x);
        rep(i,mid+1,r) move(z,x);
    }
}
int main(){
       int n=read();
       down(i,n,1) a[0][i]=read();
       N[0]=n;
       dfs(0,1,n,0);
       printf("%d\n",tot);
       rep(i,1,tot) printf("%d %d\n",ansx[i],ansy[i]);
    return 0;
}