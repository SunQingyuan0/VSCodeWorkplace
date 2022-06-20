#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct StackNode
{
    char data;
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
bool Push(LinkStack &elem,char e)
{
    Node p=(Node)malloc(sizeof(StackNode));
    p->data=e;
    p->next=elem.base->next;
    elem.base->next=p;
    elem.length++;
    return true;
}
bool Pop(LinkStack &elem,char &e)
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
int Pcmp(char a,char b)
{
    
}
int caculate()
{
    LinkStack cache1,cache2;
    InitStack(cache1);
    InitStack(cache2);
}
int main()
{

}