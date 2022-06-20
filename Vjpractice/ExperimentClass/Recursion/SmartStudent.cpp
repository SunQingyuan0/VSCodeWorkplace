/*Description
一位教授逻辑学的教授有三名非常善于推理且精于心算的学生A，B和C。有一天,教授给他们三人出了一道题：教授在每个人脑门上贴了一张纸条并告诉他们，每个人的纸条上都写了一个正整数，且某两个数的和等于第三个。于是，每个学生都能看见贴在另外两个同学头上的整数，但却看不见自己的数。
 
这时，教授先对学生A发问了：“你能猜出自己的数吗？”A回答：“不能。”
教授又转身问学生B：“你能猜出自己的数吗？”B想了想，也回答：“不能。”
教授再问学生C同样的问题，C思考了片刻后，摇了摇头：“不能”。
接着，教授又重新问A同样的问题，再问B和C，……，经过若干轮的提问之后，当教授再次询问某人时，此人突然露出了得意的笑容，把贴在自己头上的那个数准确无误的报了出来。
 
现在，如果告诉你：教授在第N次提问时，轮到回答问题的那个人猜出了贴在自己头上的数是M，你能推断出另外两个学生的头上贴的是什么数吗？
 
[提示]
在没有人猜出自己头上的数之前，大家对教授提问的回答始终都是“不能”；而且除此之外在A，B，C之间是没有进行任何信息交流的。也就是说，每个人推断的依据仅仅是另外两个人的头上数，以及大家对教授的提问所做出的否定回答。
教授总是从学生A开始提问的。
你可以假定，这三个足够聪明的学生能够根据已知的条件在最早的轮次猜出自己的数，并且永远都不会猜错。
稍经分析和推理，你将得出以下结论：总是头上贴着最大的那个数的人最先猜出自己头上的数。
 
Input
包括若干组测试数据，其中的每一行代表一组测试数据，由两个整数N和M组成（即在教授第N次提问时，轮到回答问题的那个人猜出了贴在自己头上的数是M）。两个数之间用空格分隔开。最后，由-1 -1组成的一行标志着输入数据的结束。
0<N<500; 0<M<30000
 
Output
按照输入文件中的顺序依次给出各组数据的结果。
文件中对应每组数据的输出的第一行是一个整数p，是可能情况的总数。接下来的p行，每一行包括三个数，分别为贴在A，B，C头上的三个数。输出时，所有解按照A头上的数增序排列；在A头上的数相同的情况下，按照B头上的数增序排列。
Sample Input
5 8
3 2
2 3
-1  -1
Sample Output
3
2 8 6
5 8 3
6 8 2
1
1 1 2
1
2 3 1*/
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
#include<queue>
using namespace std;
int ans[30010][3];
int recur(int x,int y,int t)
{
    if(x==y)return t+1;
    if(x<y)return recur(y-x,x,(t+1)%3)+2;
    else return recur(y,x-y,(t+2)%3)+1;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(ans,0,30010*3*sizeof(int));
        if(n==-1&&m==-1)break;
        int cnt=0;
        for(int i=1;i<m;i++)
        {
            int x=i;
            int y=m-x;
            int Ans=recur(x,y,(n-1)%3);
            if(Ans==n)
            {
                ans[cnt][(n-1)%3]=m;
                ans[cnt][n%3]=y;
                ans[cnt][(n+1)%3]=x;
                cnt++;
            }
        }
        printf("%d\n",cnt);
        if((n-1)%3==1)
        {
            for(int i=0;i<cnt;i++)
            {
                printf("%d %d %d\n",ans[i][(n+1)%3],ans[i][(n-1)%3],ans[i][(n)%3]);
            }
        }
        else if((n-1)%3==0)
        {
            for(int i=cnt-1;i>=0;i--)
            {
                printf("%d %d %d\n",ans[i][(n-1)%3],ans[i][(n)%3],ans[i][(n+1)%3]);
            }
        }
        else
        {
            for(int i=cnt-1;i>=0;i--)
            {
                printf("%d %d %d\n",ans[i][(n)%3],ans[i][(n+1)%3],ans[i][(n-1)%3]);
            }
        }    
    } 
}