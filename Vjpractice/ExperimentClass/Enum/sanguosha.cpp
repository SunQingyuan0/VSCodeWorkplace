/*There're restraints among heroes. For example, YuJi restricts Zhu Geliang, LuXun restricts DaQiao, ZhangJiao restricts MaChao, WeiYan restricts XiaoQiao.
Today I play with friends. I know the heroes and the restraints.(If opponent's hero restraint my hero, my hero will be beaten, others my hero will beat opponent's hero)
Can you arrange my heroes' order,no matter what order of opponent's heroes, so that I can win the game?
The first line is a number T(1<=T<=50), represents the number of case. The next T blocks follow each indicates a case.
The first line is N(3<=N<=6).
The second line has N names(shorter than 20 letter).
The following N lines each contains a restraints. Restraints are given as “k b1 b2 … bk”, which means the opponent's hero restricts my hero b1, b2 … bk. (0<=K<=N)
For each case, first line output the number of case with "Yes" or "No". If Yes, output the order of your heroes separate by a space. If there are more than one order, please output the one with minimum lexicographic order.(as shown in the sample output)
Sample Input
2
3
ZhugeLiang HuangYueying ZhenJi
1 ZhugeLiang
2 HuangYueying ZhenJi
2 ZhugeLiang ZhenJi
4
MaChao YanLiangWenChou YuJin XiaoQiao
2 MaChao XiaoQiao
2 YanLiangWenChou YuJin
1 XiaoQiao
0
Sample Output
Case 1: No
Case 2: Yes
MaChao YanLiangWenChou XiaoQiao YuJin*/
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<cstring>
using namespace std;
bool check(int matrix[][10], int p, int q)
{
    if (matrix[p][q])return false;
    else
    {
        return true;
    }

}
bool win(int matrix[][10], int a[], int b[], int n)
{
    int My = 0, Enemy = 0;
    while (true)
    {
        if (check(matrix, a[Enemy], b[My]))
        {
            Enemy++;
        }
        else
        {
            My++;
        }
        if (My == n)return false;
        if (Enemy == n)return true;
    }

}
int FindNum(vector<string> Name, string Tar)
{
    int i;
    for (i = 0; i < Name.size(); i++)
    {
        if (Name[i] == Tar)return i;
    }
    return 8;
}
int main()
{
    int t;
    scanf("%d", &t);
    int k;
    for (k = 0; k < t; k++)
    {
        int n;
        scanf("%d", &n);
        vector<string> Name;
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            Name.push_back(temp);
        }
        sort(Name.begin(), Name.end());
        int matrix[10][10];
        memset(matrix, 0, 100 * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            int s;
            scanf("%d", &s);
            for (int j = 0; j < s; j++)
            {
                string temp;
                cin >> temp;
                int num = FindNum(Name, temp);
                matrix[i][num] = 1;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         printf("%d ", matrix[i][j]);
        //     }
        //     printf("\n");
        // }
        int My[10], Enemy[10];
        for (int i = 0; i < n; i++)
        {
            My[i] = i;
            Enemy[i] = i;
        }
        bool flag1 = false;
        printf("Case %d: ", k + 1);
        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                Enemy[i] = i;
            }
            bool flag = true;
            while (true)
            {
                if (!win(matrix, Enemy, My, n))
                {
                    flag = false;
                    break;
                }
                if (!next_permutation(Enemy, Enemy + n))break;
            }
            if (flag)
            {
                flag1 = true;
                printf("Yes\n");
                bool flag3 = true;
                for (int i = 0; i < n; i++)
                {
                    if (flag3)
                    {
                        cout << Name[My[i]];
                        flag3 = false;
                    }
                    else
                    {
                        cout << " " << Name[My[i]];
                    }
                }
                printf("\n");
                break;
            }
            else
            {
                if (!next_permutation(My, My + n))break;
            }
        }
        if (!flag1)printf("No\n");
    }
}