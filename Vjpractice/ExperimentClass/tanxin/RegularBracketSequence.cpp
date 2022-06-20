/*A string is called bracket sequence if it does not contain any characters other than "(" and ")". A bracket sequence is called regular if it it is possible to obtain correct arithmetic expression by inserting characters "+" and "1" into this sequence. For example, "", "(())" and "()()" are regular bracket sequences; "))" and ")((" are bracket sequences (but not regular ones), and "(a)" and "(1)+(1)" are not bracket sequences at all.

You have a number of strings; each string is a bracket sequence of length 2. So, overall you have cnt1 strings "((", cnt2 strings "()", cnt3 strings ")(" and cnt4 strings "))". You want to write all these strings in some order, one after another; after that, you will get a long bracket sequence of length 2(cnt1+cnt2+cnt3+cnt4). You wonder: is it possible to choose some order of the strings you have such that you will get a regular bracket sequence? Note that you may not remove any characters or strings, and you may not add anything either.
The input consists of four lines, i-th of them contains one integer cnti (0≤cnti≤109).
Print one integer: 1 if it is possible to form a regular bracket sequence by choosing the correct order of the given strings, 0 otherwise.
Examples
3
1
4
3

1

0
0
0
0

1

1
2
3
4

0
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
int main()
{
    long long t1,t2,t3,t4;
    while (scanf("%lld%lld%lld%lld",&t1,&t2,&t3,&t4)!=EOF)
    {
        if(t1==t4&&t1>0)printf("1\n");
        else if (t1==t4&&t1==0&&t3==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
        
    }
}