/*
相信大家都听说一个“百岛湖”的地方吧，百岛湖的居民生活在不同的小岛中，当他们想去其他的小岛时都要通过划小船来实现。现在政府决定大力发展百岛湖，发展首先要解决的问题当然是交通问题，政府决定实现百岛湖的全畅通！经过考察小组RPRush对百岛湖的情况充分了解后，决定在符合条件的小岛间建上桥，所谓符合条件，就是2个小岛之间的距离不能小于10米，也不能大于1000米。当然，为了节省资金，只要求实现任意2个小岛之间有路通即可。其中桥的价格为 100元/米。
Input
输入包括多组数据。输入首先包括一个整数T(T <= 200)，代表有T组数据。
每组数据首先是一个整数C(C <= 100),代表小岛的个数，接下来是C组坐标，代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。
Output
每组输入数据输出一行，代表建桥的最小花费，结果保留一位小数。如果无法实现工程以达到全部畅通，输出”oh!”.
Sample Input
2
2
10 10
20 20
3
1 1
2 2
1000 1000
Sample Output
1414.2
oh!
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int father[110];
struct Graph
{
    int u;
    int v;
    double dis;
}maps[10010];
int x[110],y[110];
 
void init(int n)
{
    for(int i=1;i<=n;i++) father[i]=i;
}
int find(int x)
{
    while(father[x]!=x) x=father[x];
    return x;
}
void join(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2) father[t1]=t2;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int c;
        cin >> c;
        for(int i=1;i<=c;i++)
            cin >> x[i] >> y[i];
        int edgeNum = 0;
        for(int i=1;i<=c-1;i++)
            for(int j=i+1;j<=c;j++)
            {
                double tmp = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                if(tmp>=10.0 && tmp<=1000.0)
                {
                    maps[++edgeNum].u = i;
                    maps[edgeNum].v = j;
                    maps[edgeNum].dis = tmp;
                }else continue;
            }
            
        init(c);
        sort(maps+1,maps+1+edgeNum,[](Graph x,Graph y)->bool{return x.dis < y.dis;});
        double distance = 0.0;
        for(int i=1;i<=edgeNum;i++)
            if(find(maps[i].u) != find(maps[i].v))
            {
                join(maps[i].u,maps[i].v);
                distance += maps[i].dis;
            }
        int cnt = 0;
        for(int i=1;i<=c;i++)
        {
            if(father[i]==i) cnt++;
        }
        if(cnt<=1)
            printf("%.1lf\n",distance*100.0);
        else
            cout << "oh!\n";
    }
    return 0;
}