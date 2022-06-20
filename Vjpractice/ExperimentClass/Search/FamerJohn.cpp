
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100010
int Data[N];
void BFS(int n,int k)
{
    queue<int> BFSqueue;
    BFSqueue.push(n);
    Data[n]=0;
    while (!BFSqueue.empty())
    {
        int temp=BFSqueue.front();
        if(temp==k)break;
        BFSqueue.pop();
        int n1=temp+1;
        int n2=temp-1;
        int n3=2*temp;
        if(n1<=100000)
        {
            if(Data[n1]<0)
            {
                BFSqueue.push(n1);
                Data[n1]=Data[temp]+1;
            }
        }
        if(n2<=100000)
        {
            if(Data[n2]<0)
            {
                BFSqueue.push(n2);
                Data[n2]=Data[temp]+1;
            }
        }
        if(n3<=100000)
        {
            if(Data[n3]<0)
            {
                BFSqueue.push(n3);
                 Data[n3]=Data[temp]+1;
            }
        }
    }
    printf("%d\n",Data[k]);
}
int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        memset(Data,-1,N*sizeof(int));
        if(n>=k)
        {
            printf("%d\n",n-k);
        }
        else
        {
            BFS(n,k);
        }
    }
    
}