/*CCPCfinal都要开始啦！dcm师哥居然还在看电视？？？给定若干电视节目的开始和结束时间（整点时刻），试计算出师哥最多能完整看完的节目数。
　输入数据包含多个测试实例。
　　每个测试实例的第一行只有一个整数n(n≤100)，表示节目的总数。
　　然后是n行数据，每行包括两个正整数Ti_s,Ti_e，分别表示第i个节目的开始和结束时刻。注意这n个节目的时刻表并不是有序给出的。
　　当输入的n为0时，结束输入。
对于每组输入，输出能完整看到的电视节目的个数。
　　每组输出占一行。

12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

5*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
struct Unit
{
    int start;
    int end;
};
bool cmp(Unit a,Unit b)
{
    return a.end<b.end;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        Unit Data[N];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&Data[i].start,&Data[i].end);
        }
        sort(Data,Data+n,cmp);
        int sum=1;
        int last=Data[0].end;
        for(int i=1;i<n;i++)
        {
           if(Data[i].start>=last)
           {
               sum++;
               last=Data[i].end;
           }
        }
        printf("%d\n",sum);
    }
}