/*Every city in Berland is situated on Ox axis. The government of the country decided to build new telecasting station. After many experiments Berland scientists came to a conclusion that in any city citizens displeasure is equal to product of citizens amount in it by distance between city and TV-station. Find such point on Ox axis for station so that sum of displeasures of all cities is minimal.
Input

Input begins from line with integer positive number N (0<N<15000) – amount of cities in Berland. Following N pairs (X, P) describes cities (0<X, P<50000), where X is a coordinate of city and P is an amount of citizens. All numbers separated by whitespace(s).


Output

Write the best position for TV-station with accuracy 10-5.

Sample Input

4
1 3
2 1
5 2
6 2
Sample Output
3.00000*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define N 15010
struct city
{
    double d;
    int num;
};
city Data[N];
double Dis(double station, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += fabs(station - Data[i].d) * Data[i].num;
    }
    return sum;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(Data, 0, N * sizeof(city));
        double high = 0;
        for (int i = 0; i < n; i++)
        {
            double td;
            int tn;
            scanf("%lf%d", &td, &tn);
            Data[i].d = td;
            Data[i].num = tn;
            if (td > high)high = td;
        }
        double low = 0;
        double esp = 1e-6;
        while (high - low > esp)
        {
            double lm = (low + low + high) / 3;
            double rm = (low + high + high) / 3;
            if (Dis(lm, n) > Dis(rm, n))
            {
                low = lm;
            }
            else if(Dis(lm, n) < Dis(rm, n))
            {
                high = rm;
            }
            else
            {
                low = lm;
                high = rm;
            }
            
        }
        printf("%.5lf", high);
    }

}