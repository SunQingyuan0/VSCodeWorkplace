/*A group of N people wishes to go across a river with only one boat, which can at most carry two persons. Therefore some sort of shuttle arrangement must be arranged in order to row the boat back and forth so that all people may cross. Each person has a different rowing speed; the speed of a couple is determined by the speed of the slower one. Your job is to determine a strategy that minimizes the time for these people to get across.
The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. The first line of each case contains N, and the second line contains N integers giving the time for each people to cross the river. Each case is preceded by a blank line. There won't be more than 1000 people and nobody takes more than 100 seconds to cross.
Sample Input
1
4
1 2 5 10
Sample Output
17*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> Data;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            Data.push_back(temp);
        }
        sort(Data.begin(), Data.end());
        int sum = 0;
        while (true)
        {
            if (Data.size() == 3)
            {
                sum += Data[0] + Data[1] + Data[2];
                break;
            }
            else if (Data.size() == 2)
            {
                sum += Data[1];
                break;
            }
            else if (Data.size() == 1)
            {
                sum += Data[0];
                break;
            }
            else
            {
                sum += min(Data[0] * 2 + Data[Data.size() - 1] + Data[Data.size() - 2], Data[0] + Data[1] * 2 + Data[Data.size() - 1]);
                Data.pop_back();
                Data.pop_back();
            }
        }
        printf("%d\n", sum);
    }
}