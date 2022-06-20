#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct ArcCell
{
    int vexadj;
    char *Info;
};
struct VexCell
{
    int name;
    char *Info;
};
struct GraphMatrix
{
    VexCell vexs[20];
    ArcCell arc[20][20];
    int vexnum,arcnum;
};
struct ArcNode
{
    int vexadj;
    int weight;
    ArcNode *nextarc;
    char *Info;
};
struct VexNode
{
    int data;
    ArcNode *firstarc;
};
struct GraphList
{
    VexNode vexs[20];
    int vexnum,arcnum;
};
void Listinput(GraphList elem)
{
    scanf("%d%d",&elem.vexnum,&elem.arcnum);
    for(int i=0;i<elem.vexnum;i++)
    {
        elem.vexs[i].data=i;
        elem.vexs[i].firstarc=NULL;
    }
    for(int i=0;i<elem.arcnum;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ArcNode *temp=(ArcNode*)malloc(sizeof(ArcNode));
        temp->vexadj=y;
        temp->nextarc=elem.vexs[x].firstarc;
        elem.vexs[x].firstarc=temp;
    }
}
void Matrixinput(GraphMatrix elem)
{
    scanf("%d%d",&elem.vexnum,&elem.arcnum);
    for(int i=0;i<elem.vexnum;i++)
    {
        elem.vexs[i].name=i;
        for(int j=0;j<elem.vexnum;j++)
        {
            elem.arc[i][j].vexadj=-1;
            elem.arc[i][j].Info=NULL;
        }
    }
    for(int i=0;i<elem.arcnum;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        elem.arc[x][y].vexadj=1;
        elem.arc[y][x].vexadj=1;
    }
}





