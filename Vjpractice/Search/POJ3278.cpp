#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int visit[100001];
int BFS(int n,int k)
{
    if(n>=k)
    {
        return n-k;
    }
    else
    {
        queue<int> BfsQueue;
        BfsQueue.push(n);
        visit[n]=1;
        int count=0;
        bool flag=false;
        queue<int> temp;
        for(int i=0;i<=100000;i++)
        {
            count++;
            while (!BfsQueue.empty())
            {
                int t=BfsQueue.front();
                BfsQueue.pop();
                if(t+1<=100000&&visit[t+1]==0)
                {
                    temp.push(t+1);
                    visit[t+1]=1;
                }
                if(t-1>=0&&visit[t-1]==0)
                {
                    temp.push(t-1);
                    visit[t-1]=1;
                }
                if(t*2<=100000&&visit[2*t]==0)
                {
                    temp.push(t*2);
                    visit[2*t]=1;
                }
                
            }
            while(!temp.empty())
            {
                int t=temp.front();
                temp.pop();
                if(t==k)
                {
                    flag=true;
                    break;
                }
                BfsQueue.push(t);
            }
            if(flag)break;
        }
        return count;
    }  
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {  
        memset(visit,0,sizeof(int)*100001);
        int ans=BFS(n,k);
        printf("%d",ans);
    }
}
