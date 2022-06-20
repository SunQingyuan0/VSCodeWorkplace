#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
struct LinkNode
{
    int coe;
    int exp;
    LinkNode *next;
};

int main()
{
    LinkNode head;
    LinkNode *cur;
    cur=&head;
    int k=0;
    int len;
    while (true)
    {
        int ncoe;
        cin>>ncoe;
        int nexp;
        cin>>nexp;
        char j=getchar();
        LinkNode *p=(LinkNode*)malloc(sizeof(LinkNode));
        p->coe=ncoe;
        p->exp=nexp;
        p->next=NULL;
        cur->next=p;
        cur=p;
        len++;
        if(j!=' ')break;
    }
    cur=&head;
    while (!(cur->next==NULL))
    {
        LinkNode *p=cur->next;
        int ncoe=p->coe;
        int nexp=p->exp;
        if(nexp!=0)
        {
            ncoe=ncoe*nexp;
            nexp--;
            p->coe=ncoe;
            p->exp=nexp;
        }
        else
        {
            ncoe=0;
            p->coe=ncoe;
        }
        cur=cur->next;
        if(p->coe==0&&len>1)continue;
        if(cur->next==NULL)
        {
            cout<<p->coe<<" ";
            cout<<p->exp;
        }
        else
        {
            cout<<p->coe<<" ";
            cout<<p->exp<<" ";
        }
           
    }
}