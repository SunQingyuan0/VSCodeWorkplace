/*在选举问题中，总共有n个小团体，每个小团体拥有一定数量的选票数。如果其中m个小团体的票数和超过总票数的一半，则此组合为“获胜联盟”。n个团体可形成若干个获胜联盟。一个小团体要成为一个“关键加入者”的条件是：在其所在的获胜联盟中，如果缺少了这个小团体的加入，则此联盟不能成为获胜联盟。一个小团体的权利指数是指：一个小团体在所有获胜联盟中成为“关键加入者”的次数。请你计算每个小团体的权利指数。
输入数据的第一行为一个正整数T，表示有T组测试数据。每一组测试数据的第一行为一个正整数n（0<n<=20）。第二行有n个正整数，分别表示1到n号小团体的票数。
对每组测试数据，在同一个行按顺序输出1到n号小团体的权利指数。
Sample Input
2
1
10
7
5 7 4 8 6 7 5
Sample Output
1
16 22 16 24 20 22 16*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
bool checkU(int n, int t, int* Basic, int lim, int* ans)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        if ((t & (1 << i)) == (1 << i))
        {
            sum += Basic[i];
        }
    }
    if (sum > lim)
    {
        for (i = 0; i < n; i++)
        {
            if ((t & (1 << i) )== (1 << i))
            {
                if (sum - Basic[i] <= lim)
                {
                    ans[i]++;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    int i;
    for (i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int Basic[25];
        int j;
        int sum = 0;
        for (j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            Basic[j] = temp;
            sum += temp;
        }
        sum = sum / 2;
        int ans[25];
        memset(ans, 0, 25 * sizeof(int));
        int k;
        for (k = 1; k < (1 << n); k++)
        {
            checkU(n, k, Basic, sum, ans);
        }
        bool flag1=true;
        for (k = 0; k < n; k++)
        {
            if(flag1)
            {
                printf("%d",ans[k]);
                flag1=false;
            }
            else
            {
                printf(" %d", ans[k]);
            }
        }
        printf("\n");
    }

}