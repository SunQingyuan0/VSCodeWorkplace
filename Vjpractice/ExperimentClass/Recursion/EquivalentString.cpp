/*Today on a lecture about strings Gerald learned a new definition of string equivalency. Two strings a and b of equal length are called equivalent in one of the two cases:

They are equal.
If we split string a into two halves of the same size a1 and a2, and string b into two halves of the same size b1 and b2, then one of the following is correct:
a1 is equivalent to b1, and a2 is equivalent to b2
a1 is equivalent to b2, and a2 is equivalent to b1
As a home task, the teacher gave two strings to his students and asked to determine if they are equivalent.

Gerald has already completed this home task. Now it's your turn!

Input
The first two lines of the input contain two strings given by the teacher. Each of them has the length from 1 to 200 000 and consists of lowercase English letters. The strings have the same length.

Output
Print "YES" (without the quotes), if these two strings are equivalent, and "NO" (without the quotes) otherwise.

Examples
Input
aaba
abaa
Output
YES
Input
aabb
abab
Output
NO*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=200000+50;
char a[MAXN],b[MAXN];

bool DFS(char *p1,char *p2,int len)//递归真强大 
{
    if(!strncmp(p1,p2,len))
        return true;
    if(len%2)//字符串为长度为奇数时 
        return false;
    int n=len/2;
    if( DFS(p1,p2+n,n) && DFS(p1+n,p2,n))//a 的前一半与 b 的后一半相比 b 的前一半与a的后一般相比 相等 
        return true;
    if( DFS(p1,p2,n) && DFS(p1+n,p2+n,n))//a的前一半与b的前一半相等，a的后一半与b的后一半相等 
        return true;
    return false;
}
int main()
{
    scanf("%s %s",a,b);
    if(DFS(a,b,strlen(a)))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
