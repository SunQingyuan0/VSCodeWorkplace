#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct StackNode
{
    int data;
    StackNode *next;
}*Node;
struct LinkStack
{
    Node base;
    int length;
};
bool InitStack(LinkStack &elem)
{
    elem.base=(Node)malloc(sizeof(StackNode));
    if(!elem.base)exit(-1);
    elem.base->next=NULL;
    elem.length=0;
    return true;
}
bool Push(LinkStack &elem,int e)
{
    Node p=(Node)malloc(sizeof(StackNode));
    p->data=e;
    p->next=elem.base->next;
    elem.base->next=p;
    elem.length++;
    return true;
}
bool Pop(LinkStack &elem,int &e)
{
    Node p=elem.base->next;
    elem.base->next=p->next;
    e=p->data;
    free(p);
    elem.length--;
    return true;
}
bool Empty(LinkStack elem)
{
    return elem.base->next==NULL;
}
void numberTransform(int n,int e)
{
    LinkStack cache;
    InitStack(cache);
    while (e)
    {
        Push(cache,e%n);
        e=e/n;
    }
    while (!Empty(cache))
    {
        int temp;
        Pop(cache,temp);
        printf("%d",temp);
    }   
}
int main()
{
    numberTransform(8,1348);


}