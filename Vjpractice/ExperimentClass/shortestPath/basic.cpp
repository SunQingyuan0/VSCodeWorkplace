/*在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的t-shirt。但是每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是非常累的！所以现在他们想要寻找最短的从商店到赛场的路线，你可以帮助他们吗？

Input
输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M则表示在成都有几条路。N=M=0表示输入结束。接下来M行，每行包括3个整数A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口A与路口B之间有一条路，我们的工作人员需要C分钟的时间走过这条路。
输入保证至少存在1条商店到赛场的路线。
Output
对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间
Sample Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
Sample Output
3
2*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
    int p;
    int w;
    bool operator<(const Node& b) const
    {
        return w > b.w;
    }
};
vector<Node> Matrix[110];
int Dis[110];
int visit[110];
void Input(int n, int m)
{
    memset(Dis, 10000, sizeof(int) * 110);
    memset(visit, 0, sizeof(int) * 110);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        Node temp1, temp2;
        temp1.p = a;
        temp1.w = c;
        temp2.p = b;
        temp2.w = c;
        Matrix[a].push_back(temp2);
        Matrix[b].push_back(temp1);
    }
}
void Dijkstra(int n, int m)
{
    priority_queue<Node> sup;
    Dis[1] = 0;
    Node temp = { 1,0 };
    sup.push(temp);
    while (!sup.empty())
    {
        Node temp1 = sup.top();
        sup.pop();
        int p1 = temp1.p;
        if (visit[p1])continue;
        visit[p1] = 1;
        for (int i = 0; i < Matrix[p1].size(); i++)
        {
            int p2 = Matrix[p1][i].p;
            if (Dis[p2] > Dis[p1] + Matrix[p1][i].w&&!visit[p2])
            {
                Dis[p2] = Dis[p1] + Matrix[p1][i].w;
                Node temp3 = { p2,Dis[p2] };
                sup.push(temp3);
            }
        }
    }
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)break;
        Input(n, m);
        Dijkstra(n, m);
        printf("%d\n", Dis[n]);
        for (int i = 0; i < 110; i++)
        {
            Matrix[i].clear();
        }
    }

}