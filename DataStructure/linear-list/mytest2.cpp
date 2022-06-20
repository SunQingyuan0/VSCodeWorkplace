#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
struct BitTreeNode
{
    char Data;
    BitTreeNode* Left;
    BitTreeNode* Right;
};
int TreeCount(string fir,string nor,BitTreeNode* Root)
{
    if(fir.length()==1)return 1;
    else
    {
        Root->Data=fir[0];
        BitTreeNode *LeftTree=(BitTreeNode*)malloc(sizeof(BitTreeNode));
        BitTreeNode *RightTree=(BitTreeNode*)malloc(sizeof(BitTreeNode));
        Root->Left=LeftTree;
        Root->Right=RightTree;
        int n1=nor.find(fir[0]);
        string Leftnor=nor.substr(0,n1);
        string Rightnor=nor.substr(n1+1);
        int n2=fir.find(Leftnor[Leftnor.length()-1]);
        string Leftfir=fir.substr(1,n2);
        string Rightfir=fir.substr(n2+1);
        return max(TreeCount(Leftfir,Leftnor,LeftTree)+1,TreeCount(Rightfir,Rightnor,RightTree)+1);
    }
}
int main()
{
    int count;
    cin>>count;
    string fir,nor;
    cin>>fir;
    cin>>nor;
    BitTreeNode* Root;
    Root=(BitTreeNode*)malloc(sizeof(BitTreeNode));
    cout<<TreeCount(fir,nor,Root);

}