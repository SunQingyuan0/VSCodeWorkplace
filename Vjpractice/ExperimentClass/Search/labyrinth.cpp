/*A labyrinth is the rectangular grid, each of the cells of which is either free or wall, and it's possible to move only between free cells sharing a side.

Constantine and Mike are the world leaders of composing the labyrinths. Each of them has just composed one labyrinth of size n × m, and now they are blaming each other for the plagiarism. They consider that the plagiarism takes place if there exists such a path from the upper-left cell to the lower-right cell that is the shortest for both labyrinths. Resolve their conflict and say if the plagiarism took place.

Input
In the first line two integers n and m (1 ≤ n, m ≤ 500) are written — the height and the width of the labyrinths.

In the next n lines the labyrinth composed by Constantine is written. Each of these n lines consists of m characters. Each character is equal either to «#», which denotes a wall, or to «.», which denotes a free cell.

The next line is empty, and in the next n lines the labyrinth composed by Mike is written in the same format. It is guaranteed that the upper-left and the lower-right cells of both labyrinths are free.

Output
Output «YES» if there exists such a path from the upper-left to the lower-right cell that is the shortest for both labyrinths. Otherwise output «NO».

Examples
Input
3 5
.....
.#.#.
.....
  

.....
#.#.#
.....
Output
NO
Input
3 5
.....
.#.##
.....
  

.....
##.#.
.....
Output
YES*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct Point
{
    int x;
    int y;
};
Point Direct[5]={{1,0},{-1,0},{0,-1},{0,1}};
#define N 510
int Data1[N][N];
int Data2[N][N];
vector<int> ans1[N]; 
vector<int> ans2[N];
void DFS(int count,Point start,int direct)
{
    
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(Data1,0,N*N*sizeof(int));
        memset(Data2,0,N*N*sizeof(int));
        for(int i=1;i<=n;i++)
        {
            string temp;
            cin>>temp;
            for(int j=1;j<=m;j++)
            {
                if(temp[j-1]=='.')Data1[i][j]=0;
                if(temp[j-1]=='#')Data1[i][j]=-1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            string temp;
            cin>>temp;
            for(int j=1;j<=m;j++)
            {
                if(temp[j-1]=='.')Data2[i][j]=0;
                if(temp[j-1]=='#')Data2[i][j]=-1;
            }
        }

    }
    
}

