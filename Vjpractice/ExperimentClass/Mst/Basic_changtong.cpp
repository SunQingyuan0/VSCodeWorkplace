/*
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
Input
测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M ( < 100 )；随后的 N
行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。
Output
对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
Sample Input
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
Sample Output
3
?
*/
#include<iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <vector>
#define N 108
using namespace std;
struct Node
{
    int x, y, len;
    friend bool operator < (const Node &a, const Node &b)
    {
        return a.len < b.len;
    }
}node[10009];
int father[N], n, m;

int find(int x)
{
    if (x != father[x])
    {
        father[x] = find(father[x]);
    }
    return father[x];
}

int main()
{
    int i, j, a, b, ans;
    while(scanf("%d%d", &n, &m), n)
    {
        ans = 0;
        for (i = 0; i <= m; i++)
        {
            father[i] = i;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].len);
        }
        sort(node, node+n);
        for (i = 0; i < n; i++)
        {
            a = find(node[i].x);
            b = find(node[i].y);
            if (a == b)
            {
                continue;
            }
            ans += node[i].len;
            father[a] = b;
        }
        a = 0;
        for (i = 1; i <= m; i++)
        {
            if (i == father[i])
            {
                a++;
            }
        }
        if (a > 1)
        {
            cout << "?\n";
        }
        else
        {
            cout << ans << endl;
        }
    }
} 