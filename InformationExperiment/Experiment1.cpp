// 霍夫曼编码
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Bittree
{
    char sign;
    int possible;
    Bittree *left,*right;
};
struct TableNode
{
    char Name;
    string Word;
};

int Slect(vector<Bittree*> Information,char target);
bool cmp(Bittree* n1,Bittree* n2);
string Datainput();
vector<Bittree*> DataDeal(string Ori);
Bittree* HuffmanTree(vector<Bittree*> Information);
void TableGenerating(Bittree* Root,vector<TableNode> &Translation,string word);
int main()
{
    string Ori=Datainput();
    vector<Bittree*> Information=DataDeal(Ori);
    Bittree *Root=HuffmanTree(Information);
    vector<TableNode> Translation;
    string word="";
    TableGenerating(Root,Translation,word);
    cout<<"\n";
    cout<<"编码后的码表为："<<"\n";
    for(int i=0;i<Translation.size();i++)
    {
        cout<<Translation[i].Name<<" "<<Translation[i].Word<<"\n";
    }

}
string Datainput()
{
    cout<<"输入信源：";
    string Ori;
    cin>>Ori; 
    return Ori;
}
int Slect(vector<Bittree*> Information,char target)
{
    int i;
    int count=Information.size();
    for(i=0;i<Information.size();i++)
    {
        if(Information[i]->sign==target)
        {
            count=i;
            break;
        }
    }
    return count;
}
bool cmp(Bittree* n1,Bittree* n2)
{
    return (n1->possible)<(n2->possible);
}
vector<Bittree*> DataDeal(string Ori)
{
    vector<Bittree*> Information;
    int i=0;
    int p;
    for(i=0;i<Ori.length();i++)
    {
        p=Slect(Information,Ori[i]);
        if(p==Information.size())
        {
           Bittree* temp=new Bittree;
           temp->sign=Ori[i];
           temp->possible=1;
           temp->left=NULL;
           temp->right=NULL;
           Information.push_back(temp);
        }
        else
        {
            Information[p]->possible++;
        }   
    }
    sort(Information.begin(),Information.end(),cmp);
    return Information;
}
Bittree* HuffmanTree(vector<Bittree*> Information)
{
    vector<Bittree*>::iterator p;
    while (Information.size()!=1)
    {
        Bittree* n1=new Bittree;
        n1->possible=Information[0]->possible+Information[1]->possible;
        n1->sign='*';
        n1->left=Information[0];
        n1->right=Information[1];
        Information.erase(Information.begin(),Information.begin()+2);
        Information.push_back(n1);
        sort(Information.begin(),Information.end(),cmp);
    }
    return Information[0];
}
void TableGenerating(Bittree* Root,vector<TableNode> &Translation,string word)
{
    if((Root->right!=NULL)||(Root->left!=NULL))
    {
        TableGenerating(Root->left,Translation,word+'0');
        TableGenerating(Root->right,Translation,word+'1');
    }
    else
    {
        TableNode n1;
        n1.Name=Root->sign;
        n1.Word=word;
        Translation.push_back(n1);
    }
}