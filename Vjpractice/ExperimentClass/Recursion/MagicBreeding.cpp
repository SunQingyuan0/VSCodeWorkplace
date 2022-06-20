/*Nikita and Sasha play a computer game where you have to breed some magical creatures. Initially, they have k creatures numbered from 1 to k. Creatures have n different characteristics.

Sasha has a spell that allows to create a new creature from two given creatures. Each of its characteristics will be equal to the maximum of the corresponding characteristics of used creatures. Nikita has a similar spell, but in his spell, each characteristic of the new creature is equal to the minimum of the corresponding characteristics of used creatures. A new creature gets the smallest unused number.

They use their spells and are interested in some characteristics of their new creatures. Help them find out these characteristics.

Input
The first line contains integers n, k and q (1 ≤ n ≤ 105, 1 ≤ k ≤ 12, 1 ≤ q ≤ 105) — number of characteristics, creatures and queries.

Next k lines describe original creatures. The line i contains n numbers ai1, ai2, ..., ain (1 ≤ aij ≤ 109) — characteristics of the i-th creature.

Each of the next q lines contains a query. The i-th of these lines contains numbers ti, xi and yi (1 ≤ ti ≤ 3). They denote a query:

ti = 1 means that Sasha used his spell to the creatures xi and yi.
ti = 2 means that Nikita used his spell to the creatures xi and yi.
ti = 3 means that they want to know the yi-th characteristic of the xi-th creature. In this case 1 ≤ yi ≤ n.
It's guaranteed that all creatures' numbers are valid, that means that they are created before any of the queries involving them.

Output
For each query with ti = 3 output the corresponding characteristic.

Examples
Input
2 2 4
1 2
2 1
1 1 2
2 1 2
3 3 1
3 4 2
Output
2
1
Input
5 3 8
1 2 3 4 5
5 1 2 3 4
4 5 1 2 3
1 1 2
1 2 3
2 4 5
3 6 1
3 6 2
3 6 3
3 6 4
3 6 5
Output
5
2
2
3
4*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
const LL mod=998244353;
int a[15][maxn];

bitset<4096> s[maxn];//1<<12=4096
int main()
{
    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
//    for(int i=1;i<=M;i++)
//    {
//        for(int j=1;j<=N;j++)
//        {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=1;i<4096;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(i&(1<<(j-1))) s[j].set(i);
        }
    }
//    for(int i=1;i<=M;i++) cout<<s[i]<<endl;
    int tot=M+1;
    for(int i=1;i<=Q;i++)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1) s[tot++]=s[x]|s[y];
        else if(t==2) s[tot++]=s[x]&s[y];
        else
        {
            vector<pair<int,int> >v;
            for(int j=1;j<=M;j++) v.push_back({a[j][y],j});
            sort(v.begin(),v.end(),greater<pair<int,int> >());
//            for(int j=0;j<M;j++) cout<<v[j].first<<" "<<v[j].second<<endl;
            int b=0;
            for(int j=0;j<M;j++)
            {
                b|=(1<<(v[j].second-1));
//                cout<<"b:"<<b<<endl;
                if(s[x][b])
                {
                    printf("%d\n",a[v[j].second][y]);
                    break;
                }
            }
        }
    }
    return 0;
}