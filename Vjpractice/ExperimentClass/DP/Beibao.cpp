/*在N件物品取出若干件放在容量为W的背包里，每件物品的体积为W1，W2……Wn（Wi为整数），与之相对应的价值为P1,P2……Pn（Pi为整数）。求背包能够容纳的最大价值。

其中1 <= N <= 100，1 <= W <= 10000，每个物品1 <= Wi, Pi <= 10000。

Input
第1行输入两个整数N和W； 第2 ~ N+1行，每行两个整数Wi和Pi，分别表示每个物品的体积和价值。
Output
输出可以容纳的最大价值。
Sample Input
3 6
2 5
3 8
4 9
Sample Output
14*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[10086] = {0};
int main(){
    int n,W,w,p;
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> w >> p;
        for(int j = W; j >= w; j--){
            dp[j] = max(dp[j],dp[j-w]+p);
        }
    }
int nnn;
    cout << dp[W] << endl;
    return 0;
}
