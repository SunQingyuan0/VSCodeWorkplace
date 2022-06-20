#include"../Stack/MySqStack.h"
#include<cstdio>
#include<stdlib.h>
#define STACK_INIT_SIZE 80
#define STACKINCREMENT 10
SqStack::SqStack()
{
    stacksize=0;
}
bool SqStack::empty()const
{
    if(stacksize==0)
    return true;
    else
    {
        return false;
    }
}
Status SqStack::InitStack()
{
    base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!base)exit(OVERFLOW); 
    top=base;
    stacksize=STACK_INIT_SIZE;
    return OK;
}
bool SqStack::full()const
{
    if(top-base>=stacksize)return true;
    else
    {
        return false;
    }
    
}
Status SqStack::Push(ElemType e)
{
    if(full())
    {
        base=(ElemType *)realloc(base,(stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!base)exit(OVERFLOW);
        top=base+stacksize;
        stacksize+=STACKINCREMENT;
    }
    *top++=e;
    return OK;
}
Status SqStack::pop()
{
    if(empty())return ERROR;
    
}