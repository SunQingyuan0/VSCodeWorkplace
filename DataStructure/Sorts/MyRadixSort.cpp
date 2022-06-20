#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode* next;
};
struct MyQueue
{
    QueueNode* base;
    QueueNode* top;
};
bool InitQueue(MyQueue& Data)
{
    Data.base=(QueueNode*)malloc(sizeof(QueueNode));
    if(!Data.base)exit(-1);
    Data.top=Data.base;
    Data.base->next=NULL;
    return true;
}
bool EnQueue(MyQueue& Data,int e)
{
    QueueNode *temp=(QueueNode*)malloc(sizeof(QueueNode));
    if(!temp)exit(-1);
    temp->data=e;
    temp->next=NULL;
    Data.top->next=temp;
    Data.top=temp;
    Data.top->next=NULL;
    return true;
}
bool DeQueue(MyQueue& Data,int &e)
{
    if(Data.base==Data.top)return false;
    QueueNode *temp=Data.base->next;
    Data.base->next=temp->next;
    e=temp->data;
    if(temp==Data.top)Data.top=Data.base;
    free(temp);
    return true;
}
bool EmptyQueue(MyQueue Data)
{
    return Data.base==Data.top;
}
int GetNumber(int e,int m)
{
    int i,t;
    for(i=0;i<m;i++)
    {
        t=e%10;
        e=e/10;
    }
    return t;
}
void RadixSort(int *elem,int n,int l)
{
    MyQueue Data;
    InitQueue(Data);
    for(int i=0;i<l;i++)
    {
        EnQueue(Data,elem[i]);
    }
    MyQueue radix[10];
    for(int i=0;i<10;i++)
    {
        InitQueue(radix[i]);
    }
    int i,j;
    for(i=1;i<=n;i++)
    {
        while(!EmptyQueue(Data))
        {
            int e;
            DeQueue(Data,e);
            int t=GetNumber(e,i);
            EnQueue(radix[t],e);
        }
        for(j=0;j<10;j++)
        {
            while (!EmptyQueue(radix[j]))
            {
                int e;
                DeQueue(radix[j],e);
                EnQueue(Data,e);
            }     
        }
    }
    for(i=0;i<10;i++)
    {
        int e;
        DeQueue(Data,e);
        elem[i]=e;
    }
}
int main()
{
    int a[10]={911,624,646,986,935,311,881,590,368,739};
    RadixSort(a,3,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}

