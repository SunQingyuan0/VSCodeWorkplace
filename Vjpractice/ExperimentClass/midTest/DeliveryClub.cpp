/*Petya and Vasya got employed as couriers. During the working day they are to deliver packages to n different points on the line. According to the company's internal rules, the delivery of packages must be carried out strictly in a certain order. Initially, Petya is at the point with the coordinate s1, Vasya is at the point with the coordinate s2, and the clients are at the points x1, x2, ..., xn in the order of the required visit.

The guys agree in advance who of them will deliver the package to which of the customers, and then they act as follows. When the package for the i-th client is delivered, the one who delivers the package to the (i + 1)-st client is sent to the path (it can be the same person who went to the point xi, or the other). The friend who is not busy in delivering the current package, is standing still.

To communicate with each other, the guys have got walkie-talkies. The walkie-talkies work rather poorly at great distances, so Petya and Vasya want to distribute the orders so that the maximum distance between them during the day is as low as possible. Help Petya and Vasya to minimize the maximum distance between them, observing all delivery rules.

Input
The first line contains three integers n, s1, s2 (1 ≤ n ≤ 100 000, 0 ≤ s1, s2 ≤ 109) — number of points of delivery and starting positions of Petya and Vasya.

The second line contains n integers x1, x2, ..., xn — customers coordinates (0 ≤ xi ≤ 109), in the order to make a delivery.

It is guaranteed, that among the numbers s1, s2, x1, ..., xn there are no two equal.

Output
Output the only integer, minimum possible maximal distance between couriers during delivery.

Examples
Input
2 0 10
5 6
Output
10
Input
3 2 1
3 4 5
Output
1
Input
1 4 5
2
Output
2*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 10;

int n, s1, s2, a[N]; 

bool check(int x){
    int l = a[n] - x, r = a[n] + x;
    for (int i = n - 1; i >= 1; i --){
        if (l <= a[i] && a[i] <= r)
            l = a[i] - x, r = a[i] + x;
        else{
            l = max(a[i] - x, l);
            r = min(a[i] + x, r);
            if (l > r) return 0;
        }
    }

    return (l <= s1 && s1 <= r) || (l <= s2 && s2 <= r);
}

int main(){
    scanf("%d%d%d", &n, &s1, &s2);
    if (s1 < s2) swap(s1, s2);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);

    int l = s1 - s2, r = (int)1e9, ans;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}
