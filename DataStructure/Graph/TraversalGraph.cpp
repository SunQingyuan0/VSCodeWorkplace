#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<queue>
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
        temp2->weight = w;
        temp2->nextarc = elem.vexs[y].firstarc;
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
void DFS_List(GraphList elem, int t, int* visit)
{
    printf("%d ", t);
    visit[t] = 1;
    ArcNode* p = elem.vexs[t].firstarc;
    while (p != NULL)
    {
        if (visit[p->vexadj] == 0)
        {
            DFS_List(elem, p->vexadj, visit);
        }
        p = p->nextarc;
    }
}
void DFSTraversal_List(GraphList elem)
{
    int visit[100];
    memset(visit, 0, sizeof(int) * 100);
    for (int i = 0; i < elem.vexnum; i++)
    {
        if (visit[i] == 0)DFS_List(elem, i, visit);
    }
}
void DFS_Matrix(GraphMatrix elem, int t, int* visit)
{
    printf("%d ", t);
    visit[t] = 1;
    int i;
    for (i = 0; i < elem.vexnum; i++)
    {
        if (elem.arc[t][i].vexadj > 0 && visit[i] == 0)
        {
            DFS_Matrix(elem, i, visit);

        }
    }
}
void DFSTraversal_Matrix(GraphMatrix elem)
{
    int visit[100];
    memset(visit, 0, sizeof(int) * 100);
    for (int i = 0; i < elem.vexnum; i++)
    {
        if (visit[i] == 0)DFS_Matrix(elem, i, visit);
    }
}
void BFS_List(GraphList elem, int t, int* visit)
{
    queue<VexNode> cache;
    cache.push(elem.vexs[t]);
    visit[t] = 1;
    while (!cache.empty())
    {
        printf("%d ", cache.front().data);
        ArcNode* p = cache.front().firstarc;
        cache.pop();
        while (p != NULL)
        {
            if (visit[p->vexadj] == 0)
            {
                cache.push(elem.vexs[p->vexadj]);
                visit[p->vexadj] = 1;
            }
            p = p->nextarc;
        }
    }
}
void BFS_Matrix(GraphMatrix elem, int t, int* visit)
{
    queue<int> cache;
    cache.push(t);
    visit[t] = 1;
    while (!cache.empty())
    {
        printf("%d ", cache.front());
        for (int j = 0; j < elem.vexnum; j++)
        {
            if (visit[j] == 0 && elem.arc[cache.front()][j].vexadj > 0)
            {
                cache.push(j);
                visit[j] = 1;
            }
        }
        cache.pop();
    }

}
void BFSTraversal_Matrix(GraphMatrix elem)
{
    int visit[100];
    memset(visit, 0, sizeof(int) * 100);
    for (int i = 0; i < elem.vexnum; i++)
    {
        if (visit[i] == 0)BFS_Matrix(elem, i, visit);
    }
}
void BFSTraversal_List(GraphList elem)
{
    int visit[100];
    memset(visit, 0, sizeof(int) * 100);
    for (int i = 0; i < elem.vexnum; i++)
    {
        if (visit[i] == 0)BFS_List(elem, i, visit);
    }
}
int main()
{
    GraphMatrix test1;
    GraphList test2;
    Listinput(test2);
    DFSTraversal_List(test2);
    printf("\n");
    BFSTraversal_List(test2);
    // Matrixinput(test1);
    // DFSTraversal_Matrix(test1);
    // printf("\n");
    // BFSTraversal_Matrix(test1);
}






