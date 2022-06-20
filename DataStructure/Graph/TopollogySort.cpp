#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct StackNode
{
    int data;
    StackNode* next;
}*Node;
struct LinkStack
{
    Node base;
    int length;
};
bool InitStack(LinkStack& elem)
{
    elem.base = (Node)malloc(sizeof(StackNode));
    if (!elem.base)exit(-1);
    elem.base->next = NULL;
    elem.length = 0;
    return true;
}
bool Push(LinkStack& elem, int e)
{
    Node p = (Node)malloc(sizeof(StackNode));
    p->data = e;
    p->next = elem.base->next;
    elem.base->next = p;
    elem.length++;
    return true;
}
bool Pop(LinkStack& elem, int& e)
{
    Node p = elem.base->next;
    elem.base->next = p->next;
    e = p->data;
    free(p);
    elem.length--;
    return true;
}
bool Empty(LinkStack elem)
{
    return elem.base->next == NULL;
}
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
            elem.arc[i][j].vexadj = 0;
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
void FindDegree(GraphList elem, int* InDegree)
{
    for (int i = 0; i < elem.vexnum; i++)
    {
        InDegree[i] = 0;
        for(int j=0;j<elem.vexnum;j++)
        {
            for (ArcNode* p = elem.vexs[j].firstarc; p != NULL; p = p->nextarc)
        {
            if(p->vexadj==i)InDegree[i]++;
        }

        }
    }
}
bool TopologySort(GraphList elem)
{
    LinkStack cache;
    InitStack(cache);
    int InDegree[20];
    FindDegree(elem, InDegree);
    for (int i = 0; i < elem.vexnum; i++)
    {
        if (InDegree[i] == 0)Push(cache, i);
    }
    int count = 0;
    while (!Empty(cache))
    {
        int t;
        Pop(cache, t);
        printf("%d ", t);
        count++;
        for (ArcNode* p = elem.vexs[t].firstarc; p != NULL; p = p->nextarc)
        {
            InDegree[p->vexadj]--;
            if (InDegree[p->vexadj] == 0)Push(cache, p->vexadj);
        }
    }
    if (count < elem.vexnum)return false;
    else return true;
}
int main()
{
    GraphList elem;
    Listinput(elem);
    TopologySort(elem);

}