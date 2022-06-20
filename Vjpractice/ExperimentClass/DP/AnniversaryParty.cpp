/*There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.
Input
Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N – 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form:
L K
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line
0 0
Output
Output should contain the maximal sum of guests' ratings.
Sample Input
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
Sample Output
5*/
#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x)>(y))?(x):(y)
struct type
{
    int son,bro;
} edge[6001];
int cnt,rating[6001],heads[6001],root[6001],dp[6001][2];
void AddEdge(int x,int y)
{
    ++cnt;//添加一条边
    edge[cnt].bro=heads[x];//这条边的下一条边是x的第一条边，类似于头插法建表
    edge[cnt].son=y;//这条边连接的孩子结点是y
    heads[x]=cnt;//节点x的连接的第一条边是这条边
}
void TDP(int root)
{
    int i;
    dp[root][0]=0;
    dp[root][1]=rating[root];
    for(i=heads[root]; i!=0; i=edge[i].bro)
    {
        int son=edge[i].son;
        TDP(son);
        dp[root][0]+=max(dp[son][0],dp[son][1]);
        dp[root][1]+=dp[son][0];
    }
}
int main()
{
    int i,n,x,y,sum=0;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
        scanf("%d",&rating[i]);
    while(scanf("%d%d",&x,&y),x&&y)
    {
        AddEdge(y,x);//y是x的父节点
        root[x]=1;//x不是根节点
    }
    for(i=1; i<=n; ++i)//可能有多棵树，对每一棵树的根节点利用树状动归求最大的值
        if(root[i]!=1)//该节点是根节点
        {
            TDP(i);
            sum+=max(dp[i][0],dp[i][1]);//求出根节点的最大值，并加起来
        }
    printf("%d",sum);
    return 0;
}