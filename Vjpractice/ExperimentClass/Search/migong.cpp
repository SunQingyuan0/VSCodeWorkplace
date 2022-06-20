/*洪尼玛今天准备去寻宝，在一个n*n （n行, n列）的迷宫中，存在着一个入口、一些墙壁以及一个宝藏。由于迷宫是四连通的，即在迷宫中的一个位置，只能走到与它直接相邻的其他四个位置（上、下、左、右）。现洪尼玛在迷宫的入口处，问他最少需要走几步才能拿到宝藏？若永远无法拿到宝藏，则输出-1。

Input
多组测试数据。

每组数据输入第一行为正整数n，表示迷宫大小。

接下来n行，每行包括n个字符，其中字符'.'表示该位置为空地，字符'#'表示该位置为墙壁，字符'S'表示该位置为入口，字符'E'表示该位置为宝藏，输入数据中只有这四种字符，并且'S'和'E'仅出现一次。

n≤1000

Output
输出拿到宝藏最少需要走的步数，若永远无法拿到宝藏，则输出-1。

Sample Input
5
S.#..
#.#.#
#.#.#
#...E
#....
Sample Output
7*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define N 1010
struct Point
{
    int x;
    int y;
    Point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
};
int Data[N][N];
void BFS(Point start,Point end)
{
    queue<Point> BfsQueue;
    Data[start.x][start.y]=0;
    BfsQueue.push(start);
    while (!BfsQueue.empty())
    {
        Point temp=BfsQueue.front();
        BfsQueue.pop();
        if(temp.x==end.x&&temp.y==end.y)
        {
            break;
        }
        Point n1(temp.x+1,temp.y);
        Point n2(temp.x-1,temp.y);
        Point n3(temp.x,temp.y+1);
        Point n4(temp.x,temp.y-1);
        if(n1.x<=1000&&n1.y<=1000)
        {
            if(Data[n1.x][n1.y]==-2)
            {
                BfsQueue.push(n1);
                Data[n1.x][n1.y]=Data[temp.x][temp.y]+1;
            }
        }
        if(n2.x<=1000&&n2.y<=1000)
        {
            if(Data[n2.x][n2.y]==-2)
            {
                BfsQueue.push(n2);
                Data[n2.x][n2.y]=Data[temp.x][temp.y]+1;
            }
        }
        if(n3.x<=1000&&n3.y<=1000)
        {
            if(Data[n3.x][n3.y]==-2)
            {
                BfsQueue.push(n3);
                Data[n3.x][n3.y]=Data[temp.x][temp.y]+1;
            }
        }
        if(n4.x<=1000&&n4.y<=1000)
        {
            if(Data[n4.x][n4.y]==-2)
            {
                BfsQueue.push(n4);
                Data[n4.x][n4.y]=Data[temp.x][temp.y]+1;
            }
        }
    }
    if(Data[end.x][end.y]==-2)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",Data[end.x][end.y]);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(Data,-1,N*N*sizeof(int));
        Point start(0,0),end(0,0);
        for(int i=1;i<=n;i++)
        {
            string temp;
            cin>>temp;
            for(int j=1;j<=n;j++)
            {
                if(temp[j-1]=='S')
                {
                    start.x=i;
                    start.y=j;
                    Data[i][j]=-2;
                }
                if(temp[j-1]=='E')
                {
                    end.x=i;
                    end.y=j;
                    Data[i][j]=-2;
                }
                if(temp[j-1]=='.')
                {
                    Data[i][j]=-2;
                }
                if(temp[j-1]=='#')
                {
                    Data[i][j]=-1;
                }
            }
        }
        BFS(start,end);
    }
}