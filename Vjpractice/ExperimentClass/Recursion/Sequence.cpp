/* 小白作为一个数学爱好者，很快就计算出了这个数列的通项公式。于是，小白告诉小蓝自己已经做出来了，但为了防止小蓝抄作业，小白并不想把公式公布出来。于是小白为了向小蓝证明自己的确做出来了此题以达到其炫耀的目的，想出了一个绝妙的方法：即让小蓝说一个正整数N，小白则说出 的值，如果当N很大时小白仍能很快的说出正确答案，这就说明小白的确得到了公式。但这个方法有一个很大的漏洞：小蓝自己不会做，没法验证小白的答案是否正确。作为小蓝的好友，你能帮帮小蓝吗？

Input
      输入文件第一行有且只有一个正整数T，表示测试数据的组数。

     第2～T+1行，每行一个非负整数N。


Output
      输出文件共包含T行。

第i行应包含一个不含多余前缀0的数，它的值应等于An(n为输入数据中第i+1行被读入的整数)

【样例输入】


Sample Input
3

1

3

10

Sample Output
1
2
3*/
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include<queue>
using namespace std;
typedef long long ll;
pair<ll , ll> reccur(ll  n)
{
    if (n == 0)return { 0,1 };
    if (n == 1)return { 1,1 };
    pair<ll, ll> ans;
    if (n % 2 == 0)
    {
        ans = reccur(n / 2);
        return { ans.first,ans.first + ans.second };
    }
    else
    {
        ans = reccur((n) / 2);
        return { ans.first + ans.second,ans.second };
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        pair<ll, ll> ans;
        ans = reccur(n);
        printf("%lld\n", ans.first);
    }

}