/*Given N numbers, X1, X2, ... , XN, let us calculate the difference of every pair of numbers: ∣Xi - Xj∣ (1 ≤ i ＜ j ≤ N). We can get C(N,2) differences through this work, and now your task is to find the median of the differences as quickly as you can!

Note in this problem, the median is defined as the (m/2)-th  smallest number if m,the amount of the differences, is even. For example, you have to find the third smallest one in the case of m = 6.
The input consists of several test cases.
In each test case, N will be given in the first line. Then N numbers are given, representing X1, X2, ... , XN, ( Xi ≤ 1,000,000,000  3 ≤ N ≤ 1,00,000 )
Sample Input
4
1 3 2 4
3
1 10 2
Sample Output
1
8*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
int n;
int Number[N];
bool check(int mid, int lim)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += n-(lower_bound(Number + i + 1, Number + n, Number[i] + mid) - Number);
    }
    if (sum > lim)return true;
    else
    {
        return false;
    }

}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(Number, 0, N * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &Number[i]);
        }
        sort(Number, Number + n);
        int lim = (n - 1) * n / 4;
        int r = 0, l = Number[n - 1] - Number[0];
        int ans=0;
        while (r <= l)
        {
            int mid = (r + l) / 2;
            if (check(mid, lim))
            {
                r = mid + 1;
                ans=mid;
            }
            else
            {
                l = mid - 1;
            }
        }
        printf("%d\n", ans);
    }

}