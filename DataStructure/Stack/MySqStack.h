#ifndef MYSQSTACK_H_
#define MYSQSTACK_H_
#include"../config-clanguage/configc.h"
#include<cstdio>
class SqStack
{
private:
    ElemType *base;
    ElemType *top;
    int stacksize;
public:
    SqStack();
    ~SqStack();
    Status InitStack();
    Status Push(ElemType e);
    Status pop();
    bool empty()const;
    bool full()const;
};
#endif