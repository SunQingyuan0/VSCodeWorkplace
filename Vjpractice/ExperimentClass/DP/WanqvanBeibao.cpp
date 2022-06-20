/*有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的体积是vi，价值是ci。

现在请你选取一些物品装入背包，使这些物品的体积总和不超过背包容量，且价值总和最大。

其中1<=N<=100，1<=V<=50000，1<=vi,ci<=10000。

Input
第一行输入两个数N,V，分别表示物品种类数和背包容积； 之后N行，每行两个数vi,ci，分别表示第i种物品的体积和价值；
Output
输出一个数，表示最大的价值
Sample Input
2 11
2 3
6 14
Sample Output
20*/
#include <iostream>

using namespace std;

int main() {
  int N, M;
  int best[500010] = {0};
  int value[512];
  int need[512];

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> need[i] >> value[i];

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 1; j <= M; j++) {
      if (j >= need[i])
        best[j] = max(best[j], best[j - need[i]] + value[i]);
    }
  }

  cout << best[M] << endl;

  return 0;
}