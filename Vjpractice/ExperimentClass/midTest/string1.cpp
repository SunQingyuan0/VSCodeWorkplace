/*Let's call left cyclic shift of some string t1t2t3…tn−1tn as string t2t3…tn−1tnt1.

Analogically, let's call right cyclic shift of string t as string tnt1t2t3…tn−1.

Let's say string t is good if its left cyclic shift is equal to its right cyclic shift.

You are given string s which consists of digits 0–9.

What is the minimum number of characters you need to erase from s to make it good?

Input
The first line contains single integer t (1≤t≤1000) — the number of test cases.

Next t lines contains test cases — one per line. The first and only line of each test case contains string s (2≤|s|≤2⋅105). Each character si is digit 0–9.

It's guaranteed that the total length of strings doesn't exceed 2⋅105.

Output
For each test case, print the minimum number of characters you need to erase from s to make it good.

Example
Input
3
95831
100120013
252525252525
Output
3
5
0*/
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    char m[15]={'0','1','2','3','4','5','6','7','8','9'};

    while(t--){
        int minn=100000000;
        int ch=0;
        string s;
        cin>>s;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ch=0;
                int flag=1;
                for(int k=0;k<s.length();k++){
                    if(s[k]==m[i]&&flag==1){
                        flag=0;
                        if(i==j) ch++;
                    }
                    else if(s[k]==m[j]&&flag==0){
                        flag=1;
                        if(i==j) ch++;
                        else ch=ch+2;
                    }
                }
                int len=s.length();
                minn=min(minn,len-ch);
            }
        }
        cout<<minn<<endl;
    }
}