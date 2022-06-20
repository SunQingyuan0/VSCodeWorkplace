/*7月17日是Mr.W的生日，ACM-THU为此要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体
设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M时，要求Ri > Ri+1且Hi > Hi+1
由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小
令Q = Sπ
请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小
（除Q外，以上所有数据皆为正整数）
Input
有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。
Output
仅一行，是一个正整数S（若无解则S = 0）
Sample Input
100
2
Sample Output
68
*/
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