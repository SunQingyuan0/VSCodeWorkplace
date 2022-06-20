/*Fox Ciel is playing a mobile puzzle game called "Two Dots". The basic levels are played on a board of size n × m cells, like this:


Each cell contains a dot that has some color. We will use different uppercase Latin characters to express different colors.

The key of this game is to find a cycle that contain dots of same color. Consider 4 blue dots on the picture forming a circle as an example. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

These k dots are different: if i ≠ j then di is different from dj.
k is at least 4.
All dots belong to the same color.
For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Determine if there exists a cycle on the field.

Input
The first line contains two integers n and m (2 ≤ n, m ≤ 50): the number of rows and columns of the board.

Then n lines follow, each line contains a string consisting of m characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.

Output
Output "Yes" if there exists a cycle, and "No" otherwise.

Examples
Input
3 4
AAAA
ABCA
AAAA
Output
Yes
Input
3 4
AAAA
ABCA
AADA
Output
No
Input
4 4
YYYR
BYBY
BBBY
BBBY
Output
Yes
Input
7 6
AAAAAB
ABBBAB
ABAAAB
ABABBB
ABAAAB
ABBBAB
AAAAAB
Output
Yes
Input
2 13
ABCDEFGHIJKLM
NOPQRSTUVWXYZ
Output
No*/
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
string s[60];
int vis[600][600];
int flag = 0;
int n,m;
void dfs(int x,int y,int a,int b)   //x,y表示当前点，a,b表示上面一个点。
{
    if (vis[x][y])   //如果访问过这个点，说明成环了。
    {
        flag = 1;
        return;
    } 
    vis[x][y] = 1;
    //搜前后左右，需保证A->B->C，C不可以是A这个点。  
    if (x < n - 1 && s[x+1][y] == s[x][y] && ((x+1) != a || y != b)) dfs(x+1,y,x,y);
    if (x > 0 && s[x-1][y] == s[x][y] && ((x-1) != a || y != b)) dfs(x-1,y,x,y);
    if (y < m - 1 && s[x][y+1] == s[x][y] && (x != a || (y+1) != b)) dfs(x,y+1,x,y);
    if (y > 0 && s[x][y-1] == s[x][y] && (x != a || (y-1) != b)) dfs(x,y-1,x,y);
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    } 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
                dfs(i,j,i,j);
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
