/*You are given a matrix of size n×n filled with lowercase English letters. You can change no more than k letters in this matrix.

Consider all paths from the upper left corner to the lower right corner that move from a cell to its neighboring cell to the right or down. Each path is associated with the string that is formed by all the letters in the cells the path visits. Thus, the length of each string is 2n−1.

Find the lexicographically smallest string that can be associated with a path after changing letters in at most k cells of the matrix.

A string a is lexicographically smaller than a string b, if the first different letter in a and b is smaller in a.

Input
The first line contains two integers n and k (1≤n≤2000, 0≤k≤n2) — the size of the matrix and the number of letters you can change.

Each of the next n lines contains a string of n lowercase English letters denoting one row of the matrix.

Output
Output the lexicographically smallest string that can be associated with some valid path after changing no more than k letters in the matrix.

Examples
Input
4 2
abcd
bcde
bcad
bcde
Output
aaabcde
Input
5 3
bwwwz
hrhdh
sepsp
sqfaf
ajbvw
Output
aaaepfafw
Input
7 6
ypnxnnp
pnxonpm
nxanpou
xnnpmud
nhtdudu
npmuduh
pmutsnz
Output
aaaaaaadudsnz*/
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
using namespace std;
#define N 2010
int Data[N][N];
int visit[N][N];
char temp[N];
int ans[N];
struct Point
{
    int x;
    int y;
};
Point Con;
int Max = 0;
void DFS1(int NumA, int NumK, int n, Point start)
{
    visit[start.x][start.y] = 1;
    if (Data[start.x][start.y] == 1)
    {
        NumA++;
    }
    else
    {
        NumK--;
    }
    if (NumK <= 0)
    {
        if (NumA > Max)
        {
            Max = NumA;
            Con.x=start.x;
            Con.y=start.y;
        }
        return;
    }
    Point n1, n2;
    n1.x = start.x + 1;
    n1.y = start.y;
    n2.x = start.x;
    n2.y = start.y + 1;
    if (n1.x <= n && visit[n1.x][n1.y] == 0)DFS1(NumA, NumK, n, n1);
    if (n2.y <= n && visit[n2.x][n2.y] == 0)DFS1(NumA, NumK, n, n2);
    visit[start.x][start.y] =0;
}
int FindMin(Point n1,Point n2,int n)
{
    if(n1.x==n2.x&&n1.y==n2.y)
    {
        return 0;
    }
    if(Data[n1.x][n1.y]<Data[n2.x][n2.y])
    {
        return 1;
    }
    else if(Data[n1.x][n1.y]>Data[n2.x][n2.y])
    {
        return 2;
    }
    else
    {
        Point m1,m2,m3,m4,a,b;
        m1.x=n1.x+1;
        m1.y=n1.y;
        m2.x=n1.x;
        m2.y=n1.y+1;
        m3.x=n2.x+1;
        m3.y=n2.y;
        m4.x=n2.x;
        m4.y=n2.y+1;
        if(m1.x<=n&&m2.y<=n)
        {
            int jug=FindMin(m1,m2,n);
            if(jug==2)
            {
                a.x=m2.x;
                a.y=m2.y;
            }
            else
            {
                a.x=m1.x;
                a.y=m1.y;
            }
        }
        else if(m1.x<=n&&m2.y>n)
        {
            a.x=m1.x;
            a.y=m1.y;
        }
        else
        {
             a.x=m2.x;
             a.y=m2.y;
        }
        if(m3.x<=n&&m4.y<=n)
        {
            int jug=FindMin(m3,m4,n);
            if(jug==2)
            {
                b.x=m4.x;
                b.y=m4.y;
            }
            else
            {
                b.x=m3.x;
                b.y=m3.y;
            } 
        }
        else if(m3.x<=n&&m4.y>n)
        {
            b.x=m3.x;
            b.y=m3.y;
        }
        else
        {
            b.x=m4.x;
             b.y=m4.y;
        }
        int jug2=FindMin(a,b,n);
        return jug2;      
    }
}
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        memset(Data, -1, N * N * sizeof(int));
        memset(visit, 0, N * N * sizeof(int));
        memset(ans,1,N*sizeof(int));
        Max = 0;
        Con.x = 1;
        Con.y = 1;
        if(k>=2*n-1)
        {
            for(int i=0;i<2*n-1;i++)
            {
                printf("a");
            }
            printf("\n");
        }
        else
        {
             for (int i = 1; i <= n; i++)
        {
            memset(temp, 0, N * sizeof(char));
            scanf("%s", &temp);
            for (int j = 1; j <= n; j++)
            {
                Data[i][j] = temp[j - 1] - 'a' + 1;
            }
        }
        Point start;
        start.x = 1;
        start.y = 1;
        DFS1(k, k, n, start);
        for(int i=0;i<Max;i++)
        {
            ans[i]=1;
        }
        int lim=2*n-1-Max;
        for(int i=0;i<lim;i++)
        {

            Point n1,n2;
            n1.x=Con.x+1;
            n1.y=Con.y;
            n2.x=Con.x;
            n2.y=Con.y+1;
            if(n1.x<=n&&n2.y<=n)
            {
                if(Data[n1.x][n1.y]<Data[n2.x][n2.y])
                {
                    ans[Max+i]=Data[n1.x][n1.y];
                    Con.x=n1.x;
                    Con.y=n1.y;
                }
                else if(Data[n1.x][n1.y]>Data[n2.x][n2.y])
                {
                    ans[Max+i]=Data[n2.x][n2.y];
                    Con.x=n2.x;
                    Con.y=n2.y;
                }
                else
                {
                    int jug=FindMin(n1,n2,n);
                    if(jug==2)
                    {
                        ans[Max+i]=Data[n2.x][n2.y];
                        Con.x=n2.x;
                        Con.y=n2.y;
                    }
                    else
                    {
                        ans[Max+i]=Data[n1.x][n1.y];
                        Con.x=n1.x;
                        Con.y=n1.y;
                    }
                    
                }
            }
            else if(n1.x<=n&&n2.y>n)
            {
                ans[Max+i]=Data[n1.x][n1.y];
                Con.x=n1.x;
                    Con.y=n1.y;
            }
            else
            {
                ans[Max+i]=Data[n2.x][n2.y];
                Con.x=n2.x;
                Con.y=n2.y;
            }
            
        }
        for(int i=0;i<2*n-1;i++)
        {
            printf("%c",ans[i]+'a'-1);
        }
        printf("\n");
        }
    }
}