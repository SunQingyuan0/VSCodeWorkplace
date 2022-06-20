/*You are given n switches and m lamps. The i-th switch turns on some subset of the lamps. This information is given as the matrix a consisting of n rows and m columns where ai, j = 1 if the i-th switch turns on the j-th lamp and ai, j = 0 if the i-th switch is not connected to the j-th lamp.

Initially all m lamps are turned off.

Switches change state only from "off" to "on". It means that if you press two or more switches connected to the same lamp then the lamp will be turned on after any of this switches is pressed and will remain its state even if any switch connected to this lamp is pressed afterwards.

It is guaranteed that if you push all n switches then all m lamps will be turned on.

Your think that you have too many switches and you would like to ignore one of them.

Your task is to say if there exists such a switch that if you will ignore (not use) it but press all the other n - 1 switches then all the m lamps will be turned on.
The first line of the input contains two integers n and m (1 ≤ n, m ≤ 2000) — the number of the switches and the number of the lamps.

The following n lines contain m characters each. The character ai, j is equal to '1' if the i-th switch turns on the j-th lamp and '0' otherwise.

It is guaranteed that if you press all n switches all m lamps will be turned on.
Print "YES" if there is a switch that if you will ignore it and press all the other n - 1 switches then all m lamps will be turned on. Print "NO" if there is no such switch.
Examples
4 5
10101
01000
00111
10000
YES
4 5
10100
01000
00110
00101
NO*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
int matrix[10000][2010];
int Against[2010];
bool check(int Against[], int matrix[][2010], int num, int n)
{
    int i;
    bool flag = true;
    for (i = 0; i < n; i++)
    {
        if (Against[i] - matrix[num][i] <= 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        memset(matrix, 0, 10000 * 2010 * sizeof(int));
        memset(Against, 0, 2010 * sizeof(int));
        int i, j;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                int temp;
                scanf("%1d", &temp);
                matrix[i][j] = temp;
                Against[j] += temp;
            }
        }
        bool flag = false;
        for (i = 0; i < m; i++)
        {
            if (check(Against, matrix, i, n))
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }


    }

}