#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int BinarySearch_Recursion(int *elem,int lo,int hi,int key)
{
    if(lo>hi)return -1;
    int mid=(lo+hi)/2;
    if(key==elem[mid])return mid;
    else if(key<elem[mid])return BinarySearch_Recursion(elem,lo,mid-1,key);
    else return BinarySearch_Recursion(elem,mid+1,hi,key);
}
int BinarySearch(int *elem,int n,int key)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(elem[mid]==key)return mid;
        else if (elem[mid]>key)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }     
    }
    if(lo>hi)return -1;
}
int main()
{
    int a[11]={0,1,2,3,4,5,6,7,8,9,10};
    printf("%d %d",BinarySearch_Recursion(a,0,9,11),BinarySearch(a,10,11));
}