/*A permutation — is a sequence of length n integers from 1 to n, in which all the numbers occur exactly once. For example, [1], [3,5,2,1,4], [1,3,2] — permutations, and [2,3,2], [4,3,1], [0] — no.

Polycarp was recently gifted a permutation a[1…n] of length n. Polycarp likes trees more than permutations, so he wants to transform permutation a into a rooted binary tree. He transforms an array of different integers into a tree as follows:

the maximum element of the array becomes the root of the tree;
all elements to the left of the maximum — form a left subtree (which is built according to the same rules but applied to the left part of the array), but if there are no elements to the left of the maximum, then the root has no left child;
all elements to the right of the maximum — form a right subtree (which is built according to the same rules but applied to the right side of the array), but if there are no elements to the right of the maximum, then the root has no right child.
For example, if he builds a tree by permutation a=[3,5,2,1,4], then the root will be the element a2=5, and the left subtree will be the tree that will be built for the subarray a[1…1]=[3], and the right one — for the subarray a[3…5]=[2,1,4]. As a result, the following tree will be built:
The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

The first line of each test case contains an integer n (1≤n≤100) — the length of the permutation.

This is followed by n numbers a1,a2,…,an — permutation a.

Output
For each test case, output n values — d1,d2,…,dn.

Example
Input
3
5
3 5 2 1 4
1
1
4
4 3 1 2
Output
1 0 2 3 1 
0 
0 1 3 2 */
#include<cstdio>
#include<cstdlib>
struct Node
{
    int num;
    int deep;
};
Node Data[110];
void Recursion(int l,int r,int Nowdeep)
{
    if(r-l<0)return;
    int MaxNum=l;
    for(int i=l;i<=r;i++)
    {
        if(Data[i].num>Data[MaxNum].num)MaxNum=i;
    }
    int r1=MaxNum-1;
    int l1=MaxNum+1;
    Data[MaxNum].deep=Nowdeep;
    Recursion(l,r1,Nowdeep+1);
    Recursion(l1,r,Nowdeep+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int t;
        scanf("%d",&t);
        for(int i=0;i<110;i++)
        {
            Data[i].deep=0;
            Data[i].num=0;
        }
        for(int i=0;i<t;i++)
        {
            scanf("%d",&Data[i].num);
        }
        Recursion(0,t-1,0);
        printf("%d",Data[0].deep);
        for(int i=1;i<t;i++)
        {
            printf(" %d",Data[i].deep);
        }
        printf("\n");
    }
}