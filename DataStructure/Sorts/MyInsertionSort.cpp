#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
void InsertionSort(int *elem,int n)
{
    int i,j;
    for(i=2;i<n;i++)
    {
        if(elem[i-1]>elem[i])
        {
            elem[0]=elem[i];
            for(j=i-1;elem[0]<elem[j];j--)
            {
                elem[j+1]=elem[j];
            }
            elem[j+1]=elem[0];
        }
    }
}
int main()
{
    int a[11]={0,86, 14, 57, 25, 11, 6, 74, 77, 71, 82};
    InsertionSort(a,11);
    for(int i=1;i<11;i++)
    {
        printf("%d ",a[i]);
    }

}