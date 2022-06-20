#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Point
{
    int x;
    int y;
};

int visit[1100][1100];
void Input(int n,Point &MyStart,Point &MyEnd)
{
    memset(visit,-1,sizeof(int)*1100*1100);
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            char t;
            scanf("%c",&t);
            if(t=='\n')
            {
                if(j>1)j--;
                else if(i>1)
                {
                    i--;
                    j=n;
                }
                else
                {
                    i--;
                    break;
                }
                
                continue;   
            }
            if(t=='S')
            {
                MyStart.x=i;
                MyStart.y=j;
                visit[i][j]=0;
            }
            else if (t=='E')
            {
                MyEnd.x=i;
                MyEnd.y=j;
                visit[i][j]=0;
            }
            else if(t=='.')
            {
                visit[i][j]=0;
            }
            else
            {
                visit[i][j]=-1;
            }
        }
    }
}
int BFS(Point MyStart,Point MyEnd)
{
    queue<Point> BfsQueue;
    int ans=-1;
    BfsQueue.push(MyStart);
    while (!BfsQueue.empty())
    {
        Point temp=BfsQueue.front();
        if(temp.x==MyEnd.x&&temp.y==MyEnd.y)break;
        BfsQueue.pop();
        if(visit[temp.x+1][temp.y]==0)
        {
            visit[temp.x+1][temp.y]=visit[temp.x][temp.y]+1;
            Point temp1=temp;
            temp1.x+=1;
            BfsQueue.push(temp1);
        }
        if(visit[temp.x-1][temp.y]==0)
        {
            visit[temp.x-1][temp.y]=visit[temp.x][temp.y]+1;
            Point temp1=temp;
            temp1.x-=1;
            BfsQueue.push(temp1);
        }
        if(visit[temp.x][temp.y+1]==0)
        {
            visit[temp.x][temp.y+1]=visit[temp.x][temp.y]+1;
            Point temp1=temp;
            temp1.y+=1;
            BfsQueue.push(temp1);
        }
        if(visit[temp.x][temp.y-1]==0)
        {
            visit[temp.x][temp.y-1]=visit[temp.x][temp.y]+1;
            Point temp1=temp;
            temp1.y-=1;
            BfsQueue.push(temp1);
        }
    }
    return visit[MyEnd.x][MyEnd.y];
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        Point MyStart,MyEnd;
        Input(n,MyStart,MyEnd);
        printf("%d",BFS(MyStart,MyEnd));
    }
}