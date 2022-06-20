#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
struct Cell
{
    char word[20];
    int Info[101];
    Cell* next;
};
struct MyList
{
    Cell* head;
    Cell* tail;
    int length;
};
bool InitList(MyList& Tar)
{
    Tar.head = (Cell*)malloc(sizeof(Cell));
    if (!Tar.head)exit(-1);
    Tar.tail = Tar.head;
    Tar.head->next = NULL;
    return true;
}
bool EnList(MyList& Tar, Cell e)
{
    Cell* p = (Cell*)malloc(sizeof(Cell));
    *p = e;
    if (p == NULL)return false;
    Tar.tail->next = p;
    Tar.tail = p;
    p->next = NULL;
    return true;
}
bool FindList(MyList& Tar, char* e, int m)
{
    Cell* p = Tar.head->next;
    bool ans = false;
    while (p != NULL)
    {
        int i, flag = 1;
        for (i = 0; i < 10; i++)
        {
            if (p->word[i] != e[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            p->Info[m] = 1;
            ans = true;
            break;
        }
        p = p->next;
    }
    return ans;
}
bool IsWord(char* e, int count)
{
    bool ans = true;
    if (count < 3)ans = false;
    int i;
    for (i = 0; i < count; i++)
    {
        if (e[i] >= 'A' && e[i] <= 'Z')e[i] += 'a' - 'A';
        if (e[i] < 'a' || e[i]>'z')
        {
            ans = false;
            break;
        }
    }
    return ans;

}
void Datainput(MyList& Data, int& n)
{
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
    {
        while (true)
        {
            char a, temp[30];
            memset(temp, 0, sizeof(char) * 30);
            int count = 0;
            while (true)
            {
                scanf("%c", &a);
                if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')))break;
                temp[count] = a;
                count++;
            }
            if (a == '#')break;
            if (IsWord(temp, count))
            {
                bool jag = FindList(Data, temp, i);
                if (!jag)
                {
                    Cell NewWord;
                    memset(NewWord.Info, 0, sizeof(int) * 101);
                    NewWord.Info[i] = 1;
                    memset(NewWord.word, 0, sizeof(char) * 20);
                    for (int j = 0; j < 10; j++)
                    {
                        NewWord.word[j] = temp[j];
                    }
                    EnList(Data, NewWord);
                }
            }
        }
    }
    int m;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        int a, b;
        int sum1 = 0, sum2 = 0, sum3 = 0;
        scanf("%d%d", &a, &b);
        Cell* p = Data.head->next;
        while (p != NULL)
        {
            if (p->Info[a] == 1)sum1++;
            if (p->Info[b] == 1)sum2++;
            if (p->Info[a] == 1 && p->Info[b] == 1)sum3++;
            p = p->next;
        }
        printf("%.2f%%\n", (float)sum3 / (float)(sum1 + sum2 - sum3) * 100);
    }
}
int main()
{
    int m, n;
    MyList Data;
    InitList(Data);
    Datainput(Data, n);
}
