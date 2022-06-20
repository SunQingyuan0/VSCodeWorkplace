#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct Huffmantree
{
    float weight;
    int parent,RChild,LChild;
    char data;
};
void CreateHuffmanTree(float *a,int n,Huffmantree *elem)
{
    int i;
    for(i=0;i<n;i++)
    {
        elem[i].weight=a[i];
    }
    int j;
    for(i=n;i<2*n-1;i++)
    {
         float small1=1000,small2=10000;
         int x1=0,x2=0;
        for(j=0;j<i;j++)
        {
            if(elem[j].parent==-1)
        {
            if(elem[j].weight<small1)
            {
                small2=small1;
                small1=elem[j].weight;
                x2=x1;
                x1=j;
            }
            if(elem[j].weight<small2&&elem[j].weight>small1)
            {
                small2=elem[j].weight;
                x2=j;
            }
        }
        }
        elem[i].weight=small2+small1;
        elem[i].LChild=x1;
        elem[i].RChild=x2;
        elem[x1].parent=i;
        elem[x2].parent=i;
    }
}
int main()
{
    float a[5];
    Huffmantree elem[9];
    for(int i=0;i<9;i++)
    {
        elem[i].weight=1000;
        elem[i].parent=elem[i].LChild=elem[i].RChild=-1;
    }
    for(int i=0;i<5;i++)
    {
        scanf("%f",&a[i]);
    }
    CreateHuffmanTree(a,5,elem);
    for(int i=0;i<9;i++)
    {
        printf("%d %f %d %d %d\n",i,elem[i].weight,elem[i].parent,elem[i].LChild,elem[i].RChild);
    }
}
