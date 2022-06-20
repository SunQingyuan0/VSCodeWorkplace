#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
void adjust(int elem[],int k,int m)
{
    int i=k,x=elem[i];
    int j=2*i;
    while (j<=m)
    {
        if(j<m&&elem[j]<elem[j+1])j=j+1;
        if(x>=elem[j])
        {
            break;
        }
        else
        {
            elem[i]=elem[j];
            i=j;
            j=2*j;
        }       
    }
    elem[i]=x;
}
void InitHeap(int elem[],int k,int m)
{
    int i;
    for(i=m/2;i>=0;i--)
    {
        adjust(elem,i,m);
    }
}
void HeapSort(int elem[],int k,int m)
{
    InitHeap(elem,k,m);
    int i;
    while (m>=0)
    {
        int temp=elem[k];
        elem[k]=elem[m];
        elem[m]=temp;
        m--;
        adjust(elem,k,m);
    }
}
int main()
{
    int a[10] = { 3,5,1,7,9,8,4,6,0,2 };
    HeapSort(a,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}