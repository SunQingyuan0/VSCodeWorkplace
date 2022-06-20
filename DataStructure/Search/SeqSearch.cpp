#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int SeqSearch(int key,int *Data,int n)
{
    Data[0]=key;
    int i;
    for(i=n-1;key!=Data[i];i--);
    return i;
}
int main()
{
    int a[11]={0,1,2,3,4,5,6,7,8,9,10};
    printf("%d ",SeqSearch(5,a,11));
}