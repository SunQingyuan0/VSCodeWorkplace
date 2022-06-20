/*在N*N的方格棋盘放置了N个皇后，使得它们不相互攻击（即任意2个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成45角的斜线上。
你的任务是，对于给定的N，求出有多少种合法的放置方法。

Input
共有若干行，每行一个正整数N≤10，表示棋盘和皇后的数量；如果N=0，表示结束。
Output
共有若干行，每行一个正整数，表示对应输入行的皇后的不同放置数量。
Sample Input
1
8
5
0
Sample Output
1
92
10*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int sum = 0;
bool check(int n, int t, int ans[])
{
    bool flag = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if (ans[i] == t||abs(t - ans[i])==abs(n - i))
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void DFS(int n, int ans[], int nn)
{
    for (int i = 1; i <= nn; i++)
    {
        ans[n] = 0;
        if (check(n, i, ans))
        {
            ans[n] = i;
            if (n == nn)
            {
                sum++;
                ans[n] = 0;
                break;
            }
            else
            {
                DFS(n + 1, ans, nn);
                ans[n] = 0;
            }
        }
    }
}
int main()
{
    int n;
    int res[15];
     int ans[15];
    memset(ans, 0, 15 * sizeof(int));
    sum = 0;
    for(int i=1;i<=10;i++)
    {
        sum=0;
        memset(ans, 0, 15 * sizeof(int));
        DFS(1,ans,i);
        res[i]=sum;
    }
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;
        printf("%d\n", res[n]);
    }

}