#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
struct section
{
    int type;
    int count;
    section() : type(0), count(0) {}
};
vector<int> init(string tar, int m)
{
    vector<int> res;
    int j = 0;
    while (res.size()<=m)
    {
        char a;
        cin>>a;
        if(a=='A')
        {
            res.push_back(1);
        }
        else if (a=='B')
        {
            res.push_back(2);
        }
        
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    string ori_data;
    cin >> ori_data;
    vector<int> data = init(ori_data, m);
    section work[33];
    int a_p = 0, b_p = 0;
    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        if (max(a_p, b_p) > n)
        {
            flag = false;
            break;
        }
        if (data[i] == 1)
        {
            if (a_p == 0)
            {
                a_p = max(a_p, b_p) + 1;
            }

            work[a_p].count++;
            if (work[a_p].count == 4)
            {
                a_p = max(a_p, b_p) + 1;
            }
        }
        else
        {
            if (b_p == 0)
            {
                b_p = max(a_p, b_p) + 1;
            }

            work[b_p].count = 1;
            b_p = max(a_p, b_p) + 1;
        }
    }
    if (max(a_p, b_p) > n)
    {
        flag = false;
    }
    if (flag)
    {
        if (data[m-1]==1)
        {
            printf("%d\n%d",a_p,work[a_p].count);
        }
        else
        {
            printf("%d\n%d",b_p,work[b_p].count);
        }
    }
    else
    {
        printf("0\n0");
    }
}