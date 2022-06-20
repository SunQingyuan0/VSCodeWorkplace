#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iterator>
#include<iostream>
#include<sstream>
#include<cstdio>
#include<ctime>
using namespace std;
#define MAX_SIZE 10000
#define SIM_STEP 100
struct free_item
{
    int begin;
    int length;
};
struct allocated_item
{
    int begin;
    int length;
    string info;
};
class free_table
{
public:
    vector<free_item> table;
};
class allocated_table
{
public:
    vector<allocated_item> table;
};
free_table freed;
allocated_table allocate;
int sum = 0;
int get_block1(int n, int p);
int get_block2(int n, int &p);
int get_block3(int n, int p);

int request(int n, int &p)
{
    int begin = get_block3(n, p);
    if (begin != -1)
    {
        allocated_item temp;
        temp.begin = begin;
        temp.length = n;
        allocate.table.push_back(temp);
    }
    return begin;
}
vector<allocated_item>::iterator find_allocate_item(int p)
{
    vector<allocated_item>::iterator i;
    for (i = allocate.table.begin(); i != allocate.table.end(); i++)
    {
        if (i->begin == p)
        {
            break;
        }
    }
    return i;
}
bool cmp1(free_item a, free_item b)
{
    return a.begin < b.begin;
}
void adjust(int begin)
{
    sort(freed.table.begin(), freed.table.end(), cmp1);
    if (freed.table.begin()->begin == begin)
    {
        if (freed.table[0].begin + freed.table[0].length == freed.table[1].begin)
        {
            freed.table[0].length += freed.table[1].length;
            freed.table.erase(freed.table.begin() + 1);
        }
    }
    else if ((freed.table.end() - 1)->begin == begin)
    {
        if ((freed.table.end() - 2)->begin + (freed.table.end() - 2)->length == (freed.table.end() - 1)->begin)
        {
            (freed.table.end() - 2)->length += (freed.table.end() - 1)->length;
            freed.table.erase(freed.table.end() - 1);
        }
    }
    else
    {
        vector<free_item>::iterator i;
        for (i = freed.table.begin(); i != freed.table.end(); i++)
        {
            if (i->begin == begin)
            {
                break;
            }
        }
        if (((i - 1)->begin + (i - 1)->length == i->begin) && (i->begin + i->length == (i + 1)->begin))
        {
            (i - 1)->length += i->length + (i + 1)->length;
            freed.table.erase(i, i + 2);
            return;

        }
        if ((!((i - 1)->begin + (i - 1)->length == i->begin)) && (i->begin + i->length == (i + 1)->begin))
        {
            i->length += (i + 1)->length;
            freed.table.erase(i + 1);
            return;
        }
        if (((i - 1)->begin + (i - 1)->length == i->begin) && (!(i->begin + i->length == (i + 1)->begin)))
        {
            (i - 1)->length += i->length;
            freed.table.erase(i);
            return;
        }
    }
}

void release(int p)
{
    vector<allocated_item>::iterator ptr = find_allocate_item(p);
    int begin = ptr->begin;
    int length = ptr->length;
    allocate.table.erase(ptr);
    free_item temp;
    temp.begin = begin;
    temp.length = length;
    freed.table.push_back(temp);
    adjust(begin);
}
int get_block1(int n, int p)
{
    int res = -1;
    for (int i = 0; i < (int)freed.table.size(); i++)
    {
        if (freed.table[i].length > n)
        {
            res = freed.table[i].begin;
            freed.table[i].begin += n;
            freed.table[i].length -= n;
            break;
        }
        if (freed.table[i].length == n)
        {
            res = freed.table[i].begin;
            vector<free_item>::iterator p = freed.table.begin() + i;
            freed.table.erase(p);
            break;
        }
        sum++;
    }
    sort(freed.table.begin(), freed.table.end(), cmp1);
    return res;
}
int get_block2(int n, int &p)
{
    int res = -1;
    int i = p;
    bool flag = true;
    while (true)
    {
        if (freed.table[i].length > n)
        {
            res = freed.table[i].begin;
            freed.table[i].begin += n;
            freed.table[i].length -= n;
            break;
        }
        if (freed.table[i].length == n)
        {
            res = freed.table[i].begin;
            vector<free_item>::iterator p = freed.table.begin() + i;
            freed.table.erase(p);
            break;
        }
        if (i == freed.table.size() - 1)
        {
            i = 0;
            continue;
        }
        i++;
        sum++;
        if (i == p - 1)
        {
            break;
        }
    }
    sort(freed.table.begin(), freed.table.end(), cmp1);
    p = i;
    return res;
}
bool cmp2(free_item a, free_item b)
{
    return a.length < b.length;
}
int get_block3(int n, int p)
{
    int res = -1;
    sort(freed.table.begin(), freed.table.end(), cmp2);
    for (int i = 0; i < (int)freed.table.size(); i++)
    {
        if (freed.table[i].length > n)
        {
            res = freed.table[i].begin;
            freed.table[i].begin += n;
            freed.table[i].length -= n;
            break;
        }
        if (freed.table[i].length == n)
        {
            res = freed.table[i].begin;
            vector<free_item>::iterator p = freed.table.begin() + i;
            freed.table.erase(p);
            break;
        }
        sum++;
    }
    sort(freed.table.begin(), freed.table.end(), cmp1);
    return res;
}
double statistic()
{
    vector<allocated_item>::iterator i;
    int sum1 = 0;
    for (i = allocate.table.begin(); i != allocate.table.end(); i++)
    {
        sum1 += i->length;
    }
    return (double)sum1 / (double)MAX_SIZE;
}
void control()
{
    int i;
    srand((unsigned int)time(NULL));
    sum = 0;
    double sum2 = 0,sum3=0;
    for (i = 0; i < SIM_STEP; i++)
    {
        int res;
        sum = 0;
        int p = 0;
        do
        {
            int num = (rand() % 1000) + 1;
            res = request(num, p);
        } while (res != -1);
        double rate = statistic();
        sum2 += rate;
        sum3 += sum;
        printf("%lf,%d\n", rate, sum);
        int len = (int)allocate.table.size();
        if (len != 0)
        {
            int p = rand() % len;
            release(allocate.table[p].begin);
        }
    }
    printf("%lf %lf", sum2 / (double)SIM_STEP, sum3 / (double)SIM_STEP);
}
void init()
{
    free_item temp;
    temp.begin = 0;
    temp.length = 10000;
    freed.table.push_back(temp);
}
int main()
{
    init();
    control();
}