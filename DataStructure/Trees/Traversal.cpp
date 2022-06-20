#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct BitTree
{
    int data1;
    char data2;
    BitTree* LChild;
    BitTree* RChild;
};
struct StackNode
{
    BitTree* Data;
    StackNode* next;
};
struct MyStack
{
    StackNode* base;
    int length;
};

void InitStack(MyStack& Data)
{
    Data.base = (StackNode*)malloc(sizeof(StackNode));
    Data.base->next = NULL;
}
void EnStack(MyStack& Data, BitTree* e)
{
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->Data = e;
    StackNode* q = Data.base->next;
    Data.base->next = p;
    p->next = q;
}
void DeStack(MyStack& Data, BitTree** e)
{
    StackNode* p = Data.base->next;
    Data.base->next = p->next;
    *e = p->Data;
    free(p);
}
bool EmptyStack(MyStack Data)
{
    return Data.base->next == NULL;
}
void CreateTree(BitTree* Root, int n, char* elem, int i)
{
    if (i > n - 1)return;
    Root->data2 = elem[i];
    if (2 * i <= n - 1)
    {
        BitTree* lc = (BitTree*)malloc(sizeof(BitTree));
        lc->LChild = NULL;
        lc->RChild = NULL;
        Root->LChild = lc;
        CreateTree(lc, n, elem, 2 * i);
    }
    if (2 * i + 1 <= n - 1)
    {
        BitTree* rc = (BitTree*)malloc(sizeof(BitTree));
        rc->LChild = NULL;
        rc->RChild = NULL;
        Root->RChild = rc;
        CreateTree(rc, n, elem, 2 * i + 1);
    }
}
void TraversalPre_R(BitTree* Root)
{
    if (Root != NULL)
    {
        printf("%c ", Root->data2);
        TraversalPre_R(Root->LChild);
        TraversalPre_R(Root->RChild);
    }
}
void VisitLeft_Pre(BitTree* Root, MyStack& Data)
{
    BitTree* p = Root;
    while (p != NULL)
    {
        printf("%c ", p->data2);
        if (p->RChild != NULL)EnStack(Data, p->RChild);
        p = p->LChild;
    }
}
void TraversalPre(BitTree* Root)
{
    MyStack Data;
    InitStack(Data);
    BitTree* p = Root;
    while (true)
    {
        VisitLeft_Pre(p, Data);
        if (EmptyStack(Data))break;
        DeStack(Data, &p);
    }
}
void TraversalIn_R(BitTree *Root)
{
    if(Root!=NULL)
    {
        TraversalIn_R(Root->LChild);
        printf("%c ",Root->data2);
        TraversalIn_R(Root->RChild);
    }
}
void VisitLeft_In(BitTree *Root,MyStack &elem)
{
    BitTree *p=Root;
    while (p!=NULL)
    {
        EnStack(elem,p);
        p=p->LChild;
    }   
}
void TraversalIn(BitTree *Root)
{
    MyStack elem;
    InitStack(elem);
    BitTree *p=Root;
    while (true)
    {
        VisitLeft_In(p,elem);
        if(EmptyStack(elem))break;
        DeStack(elem,&p);
        printf("%c ",p->data2);
        p=p->RChild;
    }

}
int main()
{
    char a[11] = { '*','a','b','c','d','e','f','g','h','i','j' };
    BitTree* Root = (BitTree*)malloc(sizeof(BitTree));
    CreateTree(Root, 11, a, 1);
    TraversalIn(Root);
}
