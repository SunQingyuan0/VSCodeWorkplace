#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct QueueNode
{
    int data;
    QueueNode *next;
}*Node;
struct LinkQueue
{
    Node base;
    Node top;
};
bool InitQueue(LinkQueue &elem)
{
    elem.base=(Node)malloc(sizeof(QueueNode));
    if(!elem.base)exit(-1);
    elem.base->next=NULL;
    elem.top=elem.base;
    return true;
}
bool Push(LinkQueue &elem,int e)
{
    Node p=(Node)malloc(sizeof(QueueNode));
    p->data=e;
    p->next=NULL;
    elem.top->next=p;
    elem.top=p;
    return true;
}
bool Pop(LinkQueue &elem,int &e)
{
    if(elem.base==elem.top)return false;
    Node p=elem.base->next;
    e=p->data;
    elem.base->next=p->next;
    if(p=elem.top)elem.top=elem.base;
    free(p);
}
bool Empty(LinkQueue elem)
{
    return elem.base==elem.top;
}
int main()
{
    
}
