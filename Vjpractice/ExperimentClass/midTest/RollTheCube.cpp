/*
This is a simple game.The goal of the game is to roll two balls to two holes each.
'B' -- ball
'H' -- hole
'.' -- land
'*' -- wall
Remember when a ball rolls into a hole, they(the ball and the hole) disappeared, that is , 'H' + 'B' = '.'.
Now you are controlling two balls at the same time.Up, down , left , right --- once one of these keys is pressed, balls exist roll to that direction, for example , you pressed up , two balls both roll up.
A ball will stay where it is if its next point is a wall, and balls can't be overlap.
Your code should give the minimun times you press the keys to achieve the goal.
Input
First there's an integer T(T<=100) indicating the case number.
Then T blocks , each block has two integers n , m (n , m <= 22) indicating size of the map.
Then n lines each with m characters.
There'll always be two balls(B) and two holes(H) in a map.
The boundary of the map is always walls(*).
Output
The minimum times you press to achieve the goal.
Tell me "Sorry , sir , my poor program fails to get an answer." if you can never achieve the goal.
Sample Input
4
6 3
***
*B*
*B*
*H*
*H*
***

4 4
****
*BB*
*HH*
****

4 4
****
*BH*
*HB*
****

5 6
******
*.BB**
*.H*H*
*..*.*
******
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
char Map[25][25]; 
int startx1,starty1; 
int startx2,starty2; 
int Next[4][2]= {0,1,1,0,0,-1,-1,0};
int vis[25][25][25][25];  
int n,m,flag;
struct node
{
    int x1,y1,x2,y2;
    int step,cnt1,cnt2;
};
void bfs()
{
    queue<node>Q;
    node now,tail; 
    now.x1=startx1 , now.y1=starty1;
    now.x2=startx2 , now.y2=starty2;
    now.step=0 ,now.cnt1=0 ,now.cnt2=0;
    Q.push(now);
    vis[now.x1][now.y1][now.x2][now.y2]=1;
    while(!Q.empty())
    {
        now=Q.front();
        Q.pop();
        if(now.cnt1&&now.cnt2) 
        {
            printf("%d\n",now.step); 
            flag=1;    
            return ;
        }
        for(int i=0; i<4; i++)
        {
            tail=now;
            if(tail.cnt1==0) 
            {
                tail.x1=now.x1+Next[i][0]; 
                tail.y1=now.y1+Next[i][1];
             if(tail.x1<0||tail.x1>=n||tail.y1<0||tail.y1>=m||Map[tail.x1][tail.y1]=='*')
                {
                    tail.x1=now.x1;
                    tail.y1=now.y1;
                }
            }
            if(tail.cnt2==0)
            {
                tail.x2=now.x2+Next[i][0];
                tail.y2=now.y2+Next[i][1];
                if(tail.x2<0||tail.x2>=n||tail.y2<0||tail.y2>=m||Map[tail.x2][tail.y2]=='*')
                {
                    tail.x2=now.x2;
                    tail.y2=now.y2;
                }
            }
            if(tail.x1==tail.x2&&tail.y1==tail.y2&&tail.cnt1==0&&tail.cnt2==0)
                continue;
            if(Map[tail.x1][tail.y1]=='H'&&(tail.x1!=tail.x2||tail.y1!=tail.y2))
            {
                tail.cnt1=1;
            }
      
            if(Map[tail.x2][tail.y2]=='H'&&(tail.x1!=tail.x2||tail.y1!=tail.y2))
            {
                tail.cnt2=1;
            }
            if(vis[tail.x1][tail.y1][tail.x2][tail.y2]==0)
            {
                tail.step++;
                Q.push(tail);
                vis[tail.x1][tail.y1][tail.x2][tail.y2]=1;
            }
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(Map,0,sizeof(Map));
        scanf("%d%d",&n,&m);
        getchar();
        int f=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%c",&Map[i][j]);
                if(Map[i][j]=='B'&&f==0)
                {
                    startx1=i;
                    starty1=j;
                    f=1;
                }
                if(Map[i][j]=='B'&&f)
                {
                    startx2=i;
                    starty2=j;
                }
            }
            getchar();
        }
          flag=0;
         bfs();
        if(flag==0)  printf("Sorry , sir , my poor program fails to get an answer.\n");
    }
    return 0;
}