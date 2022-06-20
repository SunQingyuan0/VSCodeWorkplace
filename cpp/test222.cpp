#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
#define MAX_NUM 1000
int work[MAX_NUM][MAX_NUM];
struct point
{
    int x;
    int y;
    point() : x(0), y(0) {}
    point(int xx,int yy) : x(xx), y(yy) {}
};

int main()
{
    int m,n;
    cin>>m;
    cin>>n;
    memset(work,0,sizeof(work));
    point start,end;
    cin>>start.x>>start.y;
    cin>>end.x>>end.y;
    queue<point> bfs;
    int count1=0,num1=0;
    int res1=0;
    int z;
    cin>>z;
    for(int i=0;i<z;i++)
    {
        point temp1;
        cin>>temp1.x>>temp1.y;
        work[temp1.x][temp1.y]=-1;
    }
    bfs.push(start);
    count1=1;
    while (true)
    {
        if(count1==0)
        {
            count1=bfs.size();
            num1++;
        }
        point temp2 = bfs.front();
        if(temp2.x==end.x&&temp2.y==end.y)
        {
            break;
        }
        bfs.pop();
        count1--;
        point temp3(temp2.x+1,temp2.y);
        point temp4(temp2.x-1,temp2.y);
        point temp5(temp2.x,temp2.y+1);
        point temp6(temp2.x,temp2.y-1);
        if(temp3.x>=0&&temp3.x<=end.x&&temp3.y>=0&&temp3.y<=end.y&&work[temp3.x][temp3.y]==0)
        {
            bfs.push(temp3);
            work[temp3.x][temp3.y]=-1;
        }
        if(temp4.x>=0&&temp4.x<=end.x&&temp4.y>=0&&temp4.y<=end.y&&work[temp4.x][temp4.y]==0)
        {
            bfs.push(temp4);
            work[temp4.x][temp4.y]=-1;
        }
        if(temp5.x>=0&&temp5.x<=end.x&&temp5.y>=0&&temp5.y<=end.y&&work[temp5.x][temp5.y]==0)
        {
            bfs.push(temp5);
            work[temp5.x][temp5.y]=-1;
        }
        if(temp6.x>=0&&temp6.x<=end.x&&temp6.y>=0&&temp6.y<=end.y&&work[temp6.x][temp6.y]==0)
        {
            bfs.push(temp6);
            work[temp6.x][temp6.y]=-1;
        }
    }
    while (!bfs.empty())
    {
        point temp7=bfs.front();
        bfs.pop();
        if(temp7.x==end.x&&temp7.y==end.y)
        {
            res1++;
        }
    }
    printf("%d %d",res1,num1);
}