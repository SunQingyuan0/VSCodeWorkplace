#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct BitTree
{
    int data1;
    char data2;
    int ltag;
    int rtag;
    BitTree* LChild;
    BitTree* RChild;
};
void CreateTree(BitTree* Root, int n, char* elem, int i)
{
    if (i > n - 1)return;
    Root->data2 = elem[i];
    Root->ltag = 1;
    Root->rtag = 1;
    if (2 * i <= n - 1)
    {
        Root->ltag = 0;
        BitTree* lc = (BitTree*)malloc(sizeof(BitTree));
        lc->LChild = NULL;
        lc->RChild = NULL;
        lc->ltag = 1;
        lc->rtag = 1;
        Root->LChild = lc;
        CreateTree(lc, n, elem, 2 * i);
    }
    if (2 * i + 1 <= n - 1)
    {
        Root->rtag = 0;
        BitTree* rc = (BitTree*)malloc(sizeof(BitTree));
        rc->LChild = NULL;
        rc->RChild = NULL;
        rc->ltag = 1;
        rc->rtag = 1;
        Root->RChild = rc;
        CreateTree(rc, n, elem, 2 * i + 1);
    }
}
void InThreading(BitTree* p, BitTree** pre)
{
    if (p != NULL)
    {
        InThreading(p->LChild, pre);
        if (p->LChild == NULL)
        {
            p->LChild = *pre;
            p->ltag = 1;
        }
        if ((*pre)->RChild == NULL)
        {
            (*pre)->rtag = 1;
            (*pre)->RChild = p;
        }
        *pre = p;
        InThreading(p->RChild, pre);
    }
}
void InOrderThreading(BitTree* Root, BitTree* Thrt)
{
    Thrt->ltag = 0;
    Thrt->rtag = 1;
    Thrt->RChild = Thrt;
    if (Root == NULL)
    {
        Thrt->LChild = Thrt;
    }
    else
    {
        Thrt->LChild = Root;
        BitTree* pre = Thrt;
        InThreading(Root, &pre);
        pre->RChild = Thrt;
        pre->rtag = 1;
        Thrt->RChild = pre;
    }
}
BitTree* InOrderNext(BitTree* p)
{
    if (p->rtag == 1)
    {
        return p->RChild;
    }
    else
    {
        BitTree* q;
        q = p->RChild;
        while (q->ltag == 0)
        {
            q = q->LChild;
        }
        return q;
    }
}
BitTree* InOrderPre(BitTree* p)
{
    if (p->ltag == 1)
    {
        return p->LChild;
    }
    else
    {
        BitTree* q = p->LChild;
        while (q->rtag == 0)
        {
            q = q->RChild;
        }
        return q;
    }
}
void InTraversal_Threading(BitTree* Root)
{
    BitTree* p = Root;
    while (p->ltag == 0)
    {
        p = p->LChild;
    }
    while (p->data2!='*')
    {
        printf("%c ", p->data2);
        p = InOrderNext(p);
    }
}
int main()
{
    char a[11] = { '*','a','b','c','d','e','f','g','h','i','j' };
    BitTree* Root = (BitTree*)malloc(sizeof(BitTree));
    CreateTree(Root, 11, a, 1);
    BitTree* Thrt = (BitTree*)malloc(sizeof(BitTree));
    Thrt->data2 = '*';
    InOrderThreading(Root, Thrt);
    InTraversal_Threading(Root);
}

