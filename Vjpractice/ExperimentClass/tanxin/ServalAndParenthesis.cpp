/*Serval soon said goodbye to Japari kindergarten, and began his life in Japari Primary School.

In his favorite math class, the teacher taught him the following interesting definitions.

A parenthesis sequence is a string, containing only characters "(" and ")".

A correct parenthesis sequence is a parenthesis sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example, parenthesis sequences "()()", "(())" are correct (the resulting expressions are: "(1+1)+(1+1)", "((1+1)+1)"), while ")(" and ")" are not. Note that the empty string is a correct parenthesis sequence by definition.

We define that |s| as the length of string s. A strict prefix s[1…l] (1≤l<|s|) of a string s=s1s2…s|s| is string s1s2…sl. Note that the empty string and the whole string are not strict prefixes of any string by the definition.

Having learned these definitions, he comes up with a new problem. He writes down a string s containing only characters "(", ")" and "?". And what he is going to do, is to replace each of the "?" in s independently by one of "(" and ")" to make all strict prefixes of the new sequence not a correct parenthesis sequence, while the new sequence should be a correct parenthesis sequence.

After all, he is just a primary school student so this problem is too hard for him to solve. As his best friend, can you help him to replace the question marks? If there are many solutions, any of them is acceptable.
The first line contains a single integer |s| (1≤|s|≤3⋅105), the length of the string.

The second line contains a string s, containing only "(", ")" and "?".
Examples
Input
6
(?????
Output
(()())
Input
10
(???(???(?
Output
:(*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
#define N 300010
int Data[N];
bool check(int n)
{
    bool ans=true;
    stack<int> Judge;
    int i;
    for(i=1;i<n-1;i++)
    {
        if(Data[i]==1)
        {
            Judge.push(1);
        }
        else
        {
            if(Judge.empty())
            {
                ans=false;
                break;
            }
            Judge.pop();
        }
    }
    if(i>=n-1)
    {
        if(Judge.empty())ans=true;
        else
        {
            ans=false;
        }
    }
    return ans;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
       memset(Data,0,N*sizeof(int));
       int ln=0,rn=0;
       string tar;
       cin>>tar;
       for(int i=0;i<n;i++)
       {
           char temp;
           temp=tar[i];
           if(temp=='(')
           {
               Data[i]=1;
               ln++;
           }
           if(temp==')')
           {
               Data[i]=2;
               rn++;
           }
           if(temp=='?')Data[i]=0;
       }
       if(n%2!=0)printf(":(\n");
       else
       {
           if(Data[0]==2||Data[n-1]==1)printf(":(\n");
           else
           {
               if(Data[0]==1)ln--;
               if(Data[n-1]==2)rn--;
               Data[0]=1;
               Data[n-1]=2;
               int lim=(n-2)/2;
               int lnn=lim-ln;
               int rnn=lim-rn;
               for(int i=1;i<n-1;i++)
               {
                   if(Data[i]==0)
                   {
                       if(lnn>0)
                       {
                           Data[i]=1;
                           lnn--;
                       }
                       else
                       {
                           Data[i]=2;
                           rnn--;
                       }
                   }
               }
               if(check(n))
               {
                   for(int i=0;i<n;i++)
                   {
                       if(Data[i]==1)printf("(");
                       else printf(")");
                   }
                   printf("\n");
               }
               else 
               {
                   printf(":(\n");
               }
           }
       }
    }
}