/*涵涵有两盒火柴，每盒装有 n 根火柴，每根火柴都有一个高度。现在将每盒中的火柴各自排成一列，同一列火柴的高度互不相同，两列火柴之间的距离定义为
∑ni=1(ai−bi)2，其中 ai 表示第一列火柴中第 i 个火柴的高度，bi 表示第二列火柴中第 i 个火柴的高度。

每列火柴中相邻两根火柴的位置都可以交换，请你通过交换使得两列火柴之间的距离最小。请问得到这个最小的距离，最少需要交换多少次？如果这个数字太大，请输出这个最小交换次数对 99,999,997 取模的结果。

输入格式
共三行，第一行包含一个整数 n，表示每盒中火柴的数目。

第二行有 n 个整数，每两个整数之间用一个空格隔开，表示第一列火柴的高度。

第三行有 n 个整数，每两个整数之间用一个空格隔开，表示第二列火柴的高度。

输出格式
输出共一行，包含一个整数，表示最少交换次数对 99,999,997 取模的结果。

样例 1
Input	Output
4
2 3 1 4
3 2 1 4
1
最小距离是 0，最少需要交换 1 次，比如：交换第 1 列的前 2 根火柴或者交换第 2 列的前 2 根火柴。

样例 2
Input	Output
4
1 3 4 2
1 7 2 4
2
最小距离是 10，最少需要交换 2 次，比如：交换第 1 列的中间 2 根火柴的位置，再交换第 2 列中后 2 根火柴的位置。*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
using namespace std;
#define go(i, j, n, k) for(int i = j; i <= n; i += k)
#define fo(i, j, n, k) for(int i = j; i >= n; i -= k)
#define rep(i, x) for(int i = h[x]; i; i = e[i].nxt)
#define mn 100010
#define inf 1 << 30
#define ll long long 
#define mod 99999997
#define root 0, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
inline void fre() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
}
 
struct node{
    int x, pos;
    node(int _x = 0, int _pos = 0) : x(_x), pos(_pos) {}
}a[mn], b[mn];
int z[mn << 2], c[mn], n; 
ll ans = 0;
inline void update(int rt) {
    z[rt] = z[rt << 1] + z[rt << 1 | 1];
}
inline void build(int l, int r, int rt) {
    if(l == r) { z[rt] = 0; return; }
    int m = (l + r) >> 1;
    build(lson), build(rson), update(rt);
}
inline void modify(int l, int r, int rt, int now) {
    if(l == r) { z[rt]++; return; }
    int m = (l + r) >> 1;
    if(now <= m) modify(lson, now); 
    else modify(rson, now);
    update(rt);
}
inline int query(int l, int r, int rt, int nowl, int nowr) {
    if(nowl <= l && r <= nowr) { return z[rt]; } 
    int m = (l + r) >> 1;
    if(nowl <= m) {
        if(m < nowr) return query(lson, nowl, nowr) + query(rson, nowl, nowr);
        else return query(lson, nowl, nowr);
    } else return query(rson, nowl, nowr);
}
inline bool cmp (node a, node b) { return a.x < b.x; }
inline void debug() {
    go(i, 1, n, 1) printf("%d%c", c[i], (i != n) ? ' ' : '\n');
}
int main() {
    //fre();
    n = read();
    go(i, 1, n, 1) a[i].x = read(), a[i].pos = i;
    go(i, 1, n, 1) b[i].x = read(), b[i].pos = i;
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    go(i, 1, n, 1) c[a[i].pos] = b[i].pos;
    build(root);
    fo(i, n, 1, 1) {
        ans = (ans + query(root, 0, c[i] - 1)) % mod;
        modify(root, c[i]);
    }
    cout << ans << "\n";
int nnn;
    return 0;
}