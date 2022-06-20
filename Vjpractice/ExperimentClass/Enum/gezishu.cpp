/*鸽子数字由以下过程定义：从任何正整数开始，将数字替换为其各个数位的平方和，并重复该过程，直到该数字等于1。如果不能，则这个数字不是鸽子数。
例如7是鸽子数，因为7->49->97->130->10->1。（7*7=49,4*4+9*9=97,9*9+7*7=130....如此类推）
显然1是第一个鸽子数。
有Q个询问，每个询问给出一个数k，你需要输出第k个鸽子数。
第一行一个Q，代表询问的个数（Q<=100000）
接下来Q行，每行一个数字k（k<150000）
每行输出一个数，代表第k个鸽子数
Sample Input
2
1
2
Sample Output
1
7*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
int ans[150010];
int req(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int t = n % 10;
        sum += t * t;
        n = n / 10;
    }
    return sum;
}
bool check(int n)
{
    int i;
    for (i = 0; i <= 20; i++)
    {
        if (n == 1)return true;
        n = req(n);
    }
    return false;
}
void fun()
{
    int count = 0;
        int j = 1;
        while (count<=150000)
        {
            if (check(j))
            {
                count++;
                ans[count] = j;
                j++;
            }
            else
            {
                j++;
            }
        }
}
int main()
{
    fun();
    int q;
    scanf("%d", &q);
    int i;
    for (i = 0; i < q; i++)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n",ans[k]);
    }
}