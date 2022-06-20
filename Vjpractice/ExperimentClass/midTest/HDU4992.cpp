/*
In arithmetic and computer programming, the extended Euclidean algorithm is an extension to the Euclidean algorithm, which computes, besides the greatest common divisor of integers a and b, the coefficients of Bézout's identity, that is integers x and y such that ax + by = gcd(a, b).
---Wikipedia

Today, ex-Euclid takes revenge on you. You need to calculate how many distinct positive pairs of (x, y) such as ax + by = c for given a, b and c.
Input
The first line contains a single integer T, indicating the number of test cases.

Each test case only contains three integers a, b and c.

[Technical Specification]
1. 1 <= T <= 100
2. 1 <= a, b, c <= 1 000 000
Output
For each test case, output the number of valid pairs.
Sample Input
2
1 2 3
1 1 4
Sample Output
1
3
*/
#include <cstdio>
#include <cmath>
int main()
{
    int t;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int k=0;
        for(int x = 1; x*a < c; x++)
        {
            if((c-a*x)%b == 0)
                k++;
        }
        printf("%d\n",k);
    }
    return 0;
}