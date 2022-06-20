/*Sample Input
6 3
1000 90
3239 88
2390 95
7231 84
1005 95
1001 88
Sample Output
88 5
1005 95
2390 95
1000 90
1001 88
3239 88*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define N 5010
struct Student
{
    int number;
    int score;
};
bool cmp(Student a,Student b)
{
    if(a.score==b.score)
    {
        return a.number<b.number;
    }
    else
    {
        return a.score>b.score;
    } 
}
int count(vector<Student> Data,int lim)
{
    int count=0;
    for(int i=0;i<Data.size();i++)
    {
        if(Data[i].score>=lim)count++;
    }
    return count;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        double temp1=(double)m*1.5;
        int lim=(int)temp1;
        vector<Student> Data;
        for(int i=0;i<n;i++)
        {
            Student temp;
            scanf("%d%d",&temp.number,&temp.score);
            Data.push_back(temp);
        }   
        sort(Data.begin(),Data.end(),cmp);
       int LimScore=Data[lim-1].score;
       int k=count(Data,LimScore);
       printf("%d %d\n",LimScore,k);
       for(int i=0;i<k;i++)
       {
           printf("%d %d\n",Data[i].number,Data[i].score);
       }
    }
    
}
