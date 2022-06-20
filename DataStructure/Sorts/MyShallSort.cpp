#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
void ShellInsert(int *elem,int dk,int m)
{
    int i,j;
    for(i=dk+1;i<m;i+=dk)
    {
        if(elem[i]<elem[i-dk])
        {
            elem[0]=elem[i];
            for(j=i-dk;elem[0]<elem[j];j-=dk)
            {
                elem[j+dk]=elem[j];
            }
            elem[j+dk]=elem[0];
        }
    }
}
void ShellSort(int *elem,int *dlt,int t,int m)
{
    int i;
    for(i=0;i<t;i++)
    {
        ShellInsert(elem,dlt[i],m);
    }
}
int main()
{
    int dlt[4]={8,4,2,1};
    int a[11]={0,23,87,40,29,5,65,71,55,60,63};
    ShellSort(a,dlt,4,11);
    for(int i=1;i<11;i++)
    {
        printf("%d ",a[i]);
    }
}
