/*Given m sequences, each contains n non-negative integer. Now we may select one number from each sequence to form a sequence with m integers. It's clear that we may get n ^ m this kind of sequences. Then we can calculate the sum of numbers in each sequence, and get n ^ m
 values. What we need is the smallest n sums. Could you h
 elp us?
 The first line is an integer T, which shows the number of test cases, and then T test cases follow. The first line of each case contains two integers m, n (0 < m <= 100, 0 < n <= 2000). The following m lines indicate the m sequence respectively. No integer in the sequence is greater than 10000.
 For each test case, print a line with the smallest n sums in increasing order, which is separated by a space.
 Sample Input
1
2 3
1 2 3
2 2 3
Sample Output
3 3 4*/
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 2010
int  main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        priority_queue<int,vector<int>,greater<int> > first;
        priority_queue<int,vector<int>,less<int> > second;
            int Data[SIZE];
            int count=m-1;
            for(int i=0;i<n;i++)
            {
                int temp;
                scanf("%d",&temp);
                first.push(temp);
            }
            while (count--)
            {
                for(int i=0;i<n;i++)
                scanf("%d",&Data[i]);
                for(int i=0;i<n;i++)
                {
                    int a=first.top();
                    first.pop();
                    for(int j=0;j<n;j++)
                    {
                        int b=a+Data[j];
                        if(second.size()==n&&b<second.top())
                        {
                            second.pop();
                            second.push(b);
                        }
                        else if(second.size()<n)
                        {
                            second.push(b);
                        } 
                    }
                }
                for(int i=0;i<n;i++)
                {
                    first.push(second.top());
                    second.pop();
                }
            }
            for(int i=0;i<n-1;i++)
            {
                printf("%d ",first.top());
                first.pop();
            }
            printf("%d\n",first.top());
            first.pop();            
    }
    
}