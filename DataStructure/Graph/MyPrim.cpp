#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct ArcCell
{
    int vexadj;
    char* Info;
};
struct VexCell
{
    int name;
    char* Info;
};
struct GraphMatrix
{
    VexCell vexs[20];
    ArcCell arc[20][20];
    int vexnum, arcnum;
};
struct ArcNode
{
    int vexadj;
    int weight;
    ArcNode* nextarc;
    char* Info;
};
struct VexNode
{
    int data;
    ArcNode* firstarc;
};
struct GraphList
{
    VexNode vexs[20];
    int vexnum, arcnum;
};
void Listinput(GraphList& elem)
{
    scanf("%d%d", &elem.vexnum, &elem.arcnum);
    for (int i = 0; i < elem.vexnum; i++)
    {
        elem.vexs[i].data = i;
        elem.vexs[i].firstarc = NULL;
    }
    for (int i = 0; i < elem.arcnum; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        ArcNode* temp = (ArcNode*)malloc(sizeof(ArcNode));
        temp->vexadj = y;
        temp->weight = w;
        temp->nextarc = elem.vexs[x].firstarc;
        elem.vexs[x].firstarc = temp;
        ArcNode* temp2 = (ArcNode*)malloc(sizeof(ArcNode));
        temp2->vexadj = x;
        temp->weight = w;
        temp->nextarc = elem.vexs[y].firstarc;
        elem.vexs[y].firstarc = temp2;
    }
}
void Matrixinput(GraphMatrix& elem)
{
    scanf("%d%d", &elem.vexnum, &elem.arcnum);
    for (int i = 0; i < elem.vexnum; i++)
    {
        elem.vexs[i].name = i;
        for (int j = 0; j < elem.vexnum; j++)
        {
            elem.arc[i][j].vexadj = 1000;
            elem.arc[i][j].Info = NULL;
        }
    }
    for (int i = 0; i < elem.arcnum; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        elem.arc[x][y].vexadj = w;
        elem.arc[y][x].vexadj = w;
    }
}
struct visit
{
    int lowcost;
    int parent;
    int jag;
};
void Prim(GraphMatrix elem, int t, visit* data)
{
    data[t].lowcost = 0;
    data[t].parent = -1;
    int pre = -1;
    for (int i = 0; i < elem.vexnum; i++)
    {
        int p = 0;
        int min = 1000;
        for (int j = 0; j < elem.vexnum; j++)
        {
            if (data[j].lowcost < min&&data[j].jag==0)
            {
                p = j;
                min = data[j].lowcost;
            }
        }
        data[p].jag = 1;
        for (int j = 0; j < elem.vexnum; j++)
        {
            if (elem.arc[p][j].vexadj != 1000 && data[j].jag == 0)
            {
                if (elem.arc[p][j].vexadj < data[j].lowcost)
                {
                    data[j].lowcost = elem.arc[p][j].vexadj;
                    data[j].parent = p;
                }
            }
        }
    }
}
int main()
{
    GraphMatrix test;
    visit data[100];
    Matrixinput(test);
    for (int i = 0; i < test.vexnum; i++)
    {
        data[i].jag = 0;
        data[i].lowcost = 1000;
        data[i].parent = -1;
    }
    Prim(test, 0, data);
    for (int i = 0; i < test.vexnum; i++)
    {
        printf("%d ", data[i].parent);
    }

}