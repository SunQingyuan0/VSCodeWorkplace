
/*
Machines have once again attacked the kingdom of Xions. The kingdom of Xions has N cities and N-1 bidirectional roads. The road network is such that there is a
unique path between any pair of cities.

Morpheus has the news that K Machines are planning to destroy the whole kingdom. These Machines are initially living in K different cities of the kingdom and
anytime from now they can plan and launch an attack. So he has asked Neo to destroy some of the roads to disrupt the connection among Machines. i.e after destroying those roads there should not be any path between any two Machines.

Since the attack can be at any time from now, Neo has to do this task as fast as possible. Each road in the kingdom takes certain time to get destroyed and they
can be destroyed only one at a time.

You need to write a program that tells Neo the minimum amount of time he will require to disrupt the connection among machines.
Input
The first line is an integer T represents there are T test cases. (0<T <=10)
For each test case the first line input contains two, space-separated integers, N and K. Cities are numbered 0 to N-1. Then follow N-1 lines, each containing three, space-separated integers, x y z, which means there is a bidirectional road connecting city x and city y, and to destroy this road it takes z units of time.Then follow K lines each containing an integer. The ith integer is the id of city in which ith Machine is currently located.
2 <= N <= 100,000
2 <= K <= N
1 <= time to destroy a road <= 1000,000
Output
For each test case print the minimum time required to disrupt the connection among Machines.
Sample Input
1
5 3
2 1 8
1 0 5
2 4 5
1 3 4
2
4
0
Sample Output
10

*/
#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
 
using namespace std;
 
const int N = 100000;
 
int f[N + 1];
 
void UFInit(int n)
{
    for(int i = 0; i <=n; i++)
        f[i] = i;
}
 
int Find(int a) {
    return a == f[a] ? a : f[a] = Find(f[a]);
}
 
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b) {
        f[a] = b;
        return true;
    } else
        return false;
}
 
struct Edge {
    int u, v;
    int w;
} edges[N];
 
bool cmp(Edge& a, Edge& b)
{
    return a.w > b.w;
}
 
set<int> s;
 
int main()
{
    int t, n, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
 
        for(int i = 0; i < n - 1; i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
 
        s.clear();
        for(int i = 0; i < k; i++) {
            int a;
            scanf("%d", &a);
            s.insert(a);
        }
 
        UFInit(n);
 
        // Kruscal算法
        int cnt = 0;
        long long ans = 0;
        sort(edges, edges + n - 1, cmp);
        for(int i = 0; i < n - 1; i++) {
            int u = Find(edges[i].u);
            int v = Find(edges[i].v);
            if(s.count(u) != 0 && s.count(v) != 0) {
                ans += edges[i].w;
                if(++cnt == k - 1)
                    break;
            } else {
                if(s.count(u) != 0)
                    f[v] = u;
                else
                    f[u] = v;
            }
        }
 
        printf("%lld\n", ans);
    }
 
    return 0;
}