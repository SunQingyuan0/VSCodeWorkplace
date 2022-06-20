#include<stdio.h>
#include<stdlib.h>
#include"../config-clanguage/configc.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
    int MyData;   
}ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
Status InitList_Sq(SqList &L){
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
Status ListInsert_Sq(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1) return ERROR;
    if(L.length>=L.listsize){
        ElemType * newbase;
        newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    ElemType * p;
    ElemType * q;
    q=&L.elem[i-1];
    for(p=&L.elem[L.length-1];p>=q;p--)
    {
        *(p+1)=*p;
    }
    *q=e;
    L.length++;
    return OK;
}
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
    if(i<1||i>L.length)return ERROR;
    ElemType * p=&L.elem[i-1];
    e=*p;
    ElemType *q;
    q=L.elem+L.length-1;
    for(p++;p<=q;p++)
    {
        *(p-1)=*(p);
    }
    L.length--;
    return OK;
}
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
    Lc.elem=(ElemType *)malloc((La.length+Lb.length)*sizeof(ElemType));
    Lc.listsize=La.length+Lb.length;
    Lc.length=Lc.listsize;
    ElemType *pa=La.elem;
    ElemType *pb=Lb.elem;
    ElemType *pc=Lc.elem;
    ElemType *List_a_end=La.elem+La.length-1;
    ElemType *List_b_end=Lb.elem+Lb.length-1;
    while (pa<=List_a_end&&pb<=List_b_end)
    {
        if(pa->MyData<=pb->MyData)*pc++=*pa++;
        else *pc++=*pb++;  
    }
    if(pa<List_a_end)
    {
         while (pa<List_a_end)
        {
            *pc++=*pa++;
        }  
    }
    if(pb<List_b_end)
    {
         while (pb<List_b_end)
        {
            *pc++=*pb++;
        }  
    }
}
Status DestoryList(SqList &L)
{
    free(L.elem);
    return OK;
}
Status ListEmpty(SqList L)
{
    if(L.length==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}
Status ListAdd(SqList &L,ElemType e)
{
    if(L.length>=L.listsize)
    {
        ElemType *newbase;
        newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)exit(OVERFLOW);
        L.listsize+=LISTINCREMENT;
        L.elem=newbase; 
    }
    L.elem[L.length]=e;
    L.length++;
    return OK;
}
int main()
{
    SqList test1;
    InitList_Sq(test1);
    int i;
    for(i=0;i<50;i++)
    {
        ElemType temp;
        temp.MyData=i;
        ListAdd(test1,temp);
    }
    printf("%d \n",test1.elem[25]);
    ElemType DeleteData;
    ListDelete_Sq(test1,26,DeleteData);
    printf("%d \n",test1.elem[25]);
    ElemType InsertData;
    InsertData.MyData=1;
    ListInsert_Sq(test1,26,InsertData);
    printf("%d \n",test1.elem[25]);
    DestoryList(test1);
    printf("%d \n",ListEmpty(test1));
}   