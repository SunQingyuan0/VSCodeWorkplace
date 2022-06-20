#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct BitTree
{
    int data;
    BitTree *LChild;
    BitTree *RChild;
}*BiTree;
bool MySearch(BitTree* root,BiTree &p,int key)
{
    BitTree *q=root;
    p=root;
    while(q!=NULL)
    {
        if(q->data==key)
        {
            p=q;
            return true;
        }
        else if(q->data<key)
        {
            p=q;
            q=q->RChild;
        }
        else
        {
            p=q;
            q=q->LChild;
        }   
    }
    return false;
}
bool InsertTree(BiTree &Root,int e)
{
    BitTree* search;
    bool jag=MySearch(Root,search,e);
    if(!jag)
    {
        BitTree *temp=(BitTree*)malloc(sizeof(BitTree));
        temp->data=e;
        temp->LChild=temp->RChild=NULL;
        if(search!=NULL)
        {
            if(e>search->data)
        {
            search->RChild=temp;
        }
        else
        {
            search->LChild=temp;
        }      
        }
        else
        {
            Root=temp;       
        }
        
    }
}
BiTree Search_R(BiTree Root,int e)
{
    if(Root==NULL||Root->data==e)return Root;
    if(e<Root->data)return Search_R(Root->LChild,e);
    else
    {
        return Search_R(Root->RChild,e);
    }
}
BiTree Insert_R(BiTree Root,BiTree e)
{
    if(Root==NULL)return e;
    if(Root->data==e->data)return Root;
    if(e->data<Root->data)
    {
        Root->LChild=Insert_R(Root->LChild,e);
    }
    else
    {
        Root->RChild=Insert_R(Root->RChild,e);
    }
    return Root;
}
bool Delete(BiTree &p)
{
    BiTree q,s;
    if(p->LChild==NULL)
    {
        q=p;
        p=p->RChild;
        free(q);
    }
    else if(p->RChild==NULL)
    {
        q=p;
        p=p->LChild;
        free(q);
    }
    else
    {
        q=p;
        s=p->LChild;
        while (s->RChild!=NULL)
        {
            q=s;
            s=s->RChild;
        }
        p->data=s->data;
        if(q!=p)
        {
            q->RChild=s->LChild;
        }
        else
        {
            q->LChild=s->LChild;
        }
        free(s);      
    } 
}
int main()
{
    int a[10]={4,6,8,2,9,5,7,3,1,0};
    BiTree Root=NULL;
    int i;
    for(i=0;i<10;i++)
    {
        BiTree temp=(BiTree)malloc(sizeof(BitTree));
        temp->data=a[i];
        temp->LChild=temp->RChild=NULL;
        Root=Insert_R(Root,temp);
    }
    BiTree p;
    p=Search_R(Root,8);
    printf("%d ",p->LChild->data);
}
