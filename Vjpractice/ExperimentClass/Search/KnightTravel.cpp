/*Background
The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey
around the world. Whenever a knight moves, it is two squares in one direction and one square perpendicular to this. The world of a knight is the chessboard he is living on. Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular. Can you help this adventurous knight to make travel plans?

Problem
Find a path such that the knight visits every square once. The knight can start and end on any square of the board.
Input
The input begins with a positive integer n in the first line. The following lines contain n test cases. Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard, where p describes how many different square numbers 1, . . . , p exist, q describes how many different square letters exist. These are the first q letters of the Latin alphabet: A, . . .
Output
The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the lexicographically first path that visits all squares of the chessboard with knight moves followed by an empty line. The path should be given on a single line by concatenating the names of the visited squares. Each square name consists of a capital letter followed by a number.
If no such path exist, you should output impossible on a single line.
Sample Input
3
1 1
2 3
4 3
Sample Output
Scenario #1:
A1

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4C2A3B1C3A4B2C4*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define N 70
int Data[70][70];
struct Point
{
    int x;
    int y;
};
Point Oper[8] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
bool flag = true;
int ToNum(Point t, int p, int q)
{
    if (t.x <= 0 || t.y <= 0||t.x>q||t.y>p)return -1;
    else
    {
        return(t.x - 1) * p + t.y;
    }
    
}
Point ToP(int num, int p, int q)
{
    int x1 = num / p;
    int y1 = num % p;
    Point temp;
    if (y1 == 0)
    {
        temp.x = x1;
        temp.y = p;
    }
    else
    {
        temp.x = x1 + 1;
        temp.y = y1;
    }
    return temp;
}
void Init(int p, int q)
{
    int len = p * q;
    for (int i = 1; i <= len; i++)
    {
        Point temp = ToP(i, p, q);
        for (int j = 0; j < 8; j++)
        {
            Point temp1;
            temp1.x = temp.x + Oper[j].x;
            temp1.y = temp.y + Oper[j].y;
            int test1 = ToNum(temp1, p, q);
            if (test1 >= 1 && test1 <= len)Data[i][test1] = 1;
        }
    }
}
void DFS(int start, int n, int len, int ans[], int visit[])
{
    ans[n] = start;
    visit[start] = 1;
    if (n == len && flag)
    {
        flag = false;
        return;
    }
    for (int i = 1; i <= len; i++)
    {
        if (Data[start][i] == 1 && visit[i] == 0)
        {
            DFS(i, n + 1, len, ans, visit);
            if (!flag)return;
        }
    }
    ans[n] = 0;
    visit[start]=0;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        flag = true;
        memset(Data, 0, N * N * sizeof(int));
        Init(p, q);
        int len = p * q;
        int ans[100];
        memset(ans, 0, 100 * sizeof(int));
        int visit[100];
        memset(visit, 0, sizeof(int)*100);
        for (int i = 1; i <= len; i++)
        {
            if (flag)DFS(i, 1, len, ans, visit);
        }
        if (flag)
        {
            printf("Scenario #%d:\n",k);
            printf("impossible\n");
            if (k < t)
                printf("\n");
        }
        else
        {
            printf("Scenario #%d:\n",k);
            for (int j = 1; j <= len; j++)
            {
                Point temp = ToP(ans[j], p, q);
                printf("%c%d", 'A' + temp.x - 1, temp.y);
            }
            printf("\n");
            if (k < t)
                printf("\n");
        }
    }
}
