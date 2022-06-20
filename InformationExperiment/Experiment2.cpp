// （7,4）循环码
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<bitset>
#include<cstring>
#include<ctime>
using namespace std;
#define MaxStr 30
void AsciiOutput(string OriStr,int Len,int *AsciiCode);
void CodeMaker(int* AsciiCode,int Len,int *CircleCode);
void ErrorMaker(int *CircleCode,int *ReceiveCode,int Len);
void TranslateCode(int* ReceiveCode);
void CodeGenerating(int *InformationPos,int *CircleCode,int k);
int Mod2Sum(int a,int b);
int FindHighest(int *Pur);
int main()
{
    string OriStr;
    int AsciiCode[300],CircleCode[500],ReceiveCode[500];
    printf("请输入一个字符串（a-z，A-Z,0-9）,不超过30个字符：");
    cin>>OriStr;
    AsciiOutput(OriStr,OriStr.length(),AsciiCode);
    CodeMaker(AsciiCode,OriStr.length()*8,CircleCode);
    ErrorMaker(CircleCode,ReceiveCode,OriStr.length()*14);
    TranslateCode(ReceiveCode);
}
void AsciiOutput(string OriStr,int Len,int *AsciiCode)
{
    int i,k=0;
    cout<<"二进制表示：";
    for(i=0;i<Len;i++)
    {
        for(int j=0;j<8;j++)
        {

            AsciiCode[(k+7)-j]=(int)bitset<8>(OriStr.c_str()[i])[j]; 
        }
        k+=8;
        cout<<bitset<8>(OriStr.c_str()[i])<<"\n";
    }
}
void CodeMaker(int* AsciiCode,int Len,int *CircleCode)
{
   
    cout<<"74循环码编码后：";
    int i=0,j=0,k=0;
    int EndLen=Len/4;
    for(i=0;i<EndLen;i++)
    {
        int InformationPos[4];
        for(int j=0;j<4;j++)
        {
            // printf("%d ",AsciiCode[i*4+j]);
            InformationPos[j]=AsciiCode[i*4+j];
        }
        // printf("\n");
        CodeGenerating(InformationPos,CircleCode,k);
        k++;
    }
}
void CodeGenerating(int *InformationPos,int *CircleCode,int k)
{
    int Gx[7]={0,0,0,1,0,1,1};
    int Mx[7],Rx[7];
    memset(Mx,0,7*sizeof(int));
    memset(Rx,0,7*sizeof(int));
    int i=0,j=0;
    for(i=0;i<4;i++)
    {
        Mx[i]=InformationPos[i];
    }
    // for(i=0;i<7;i++)
    // {
    //     cout<<Mx[i];
    // }
    // cout<<"\n";
    memcpy(Rx,Mx,sizeof(Mx));
    // for(i=0;i<7;i++)
    // {
    //     cout<<Rx[i];
    // }
    // cout<<"\n";
    int Gh=6-FindHighest(Gx);
    // cout<<Gh<<"\n";
    int Ju=6-FindHighest(Rx);
    if(Ju>=Gh)
    {
        while (true)
        {
            int temp1[7],temp2[7];
            memset(temp1,0,sizeof(int)*7);
            memset(temp2,0,sizeof(int)*7);
            int Rh=6-FindHighest(Rx);
            if(Rh>=Gh)
            {
                int MovingPos=Rh-Gh;
                for(i=0;i<7-MovingPos;i++)
                {
                    temp1[i]=Gx[i+MovingPos];
                }
                for(i=0;i<7;i++)
                {
                    temp2[i]=Mod2Sum(temp1[i],Rx[i]);
                }
                memcpy(Rx,temp2,sizeof(temp2));
            }
            else
            {
                break;
            }          
        }
        for(i=0;i<7;i++)
        {
            CircleCode[k*7+i]=Rx[i]+Mx[i];
            cout<<CircleCode[k*7+i];
        }
    }
    else
    {
        for(i=0;i<7;i++)
        {
            CircleCode[k*7+i]=Gx[i];
            cout<<CircleCode[k*7+i];
        }

    }
    
    
    // for(i=0;i<7;i++)
    // {
    //     cout<<Rx[i];
    // }
    // cout<<"\n";
    cout<<"\n";
    
}
void ErrorMaker(int *CircleCode,int *ReceiveCode,int Len)
{
    cout<<"纠错（一位）编码：";
    cout<<"若";
     for(int i=0;i<7;i++)
    {
        cout<<CircleCode[i]<<""; 
    }
    cout<<"在信道传输时变为";
    srand(time(NULL));
    int ErrorPos=rand()%6;
    memcpy(ReceiveCode,CircleCode,Len*sizeof(int));
    if(ReceiveCode[ErrorPos]==1)
    {
        ReceiveCode[ErrorPos]=0;
    }
    else
    {
        ReceiveCode[ErrorPos]=1;
    }
    // cout<<ErrorPos<<"\n";
    for(int i=0;i<7;i++)
    {
        cout<<ReceiveCode[i]<<""; 
    }
    cout<<"\n";
}
void TranslateCode(int* ReceiveCode)
{
    int Translate[7][4]={{1,0,1,1},{1,1,1,2},{1,1,0,3},{0,1,1,4},{1,0,0,5},{0,1,0,6},{0,0,1,7}};
    int Gx[7]={0,0,0,1,0,1,1};
    int Mx[7],Rx[7];
    memset(Mx,0,7*sizeof(int));
    memset(Rx,0,7*sizeof(int));
    int i=0,j=0;
    for(i=0;i<7;i++)
    {
        Mx[i]=ReceiveCode[i];
    }
    // for(i=0;i<7;i++)
    // {
    //     cout<<Mx[i];
    // }
    // cout<<"\n";
    memcpy(Rx,Mx,sizeof(Mx));
    // for(i=0;i<7;i++)
    // {
    //     cout<<Rx[i];
    // }
    // cout<<"\n";
    int Gh=6-FindHighest(Gx);
    // cout<<Gh<<"\n";
    int Ju=6-FindHighest(Rx);
    if(Ju>=Gh)
    {
        while (true)
        {
            int temp1[7],temp2[7];
            memset(temp1,0,sizeof(int)*7);
            memset(temp2,0,sizeof(int)*7);
            int Rh=6-FindHighest(Rx);
            if(Rh>=Gh)
            {
                int MovingPos=Rh-Gh;
                for(i=0;i<7-MovingPos;i++)
                {
                    temp1[i]=Gx[i+MovingPos];
                }
                for(i=0;i<7;i++)
                {
                    temp2[i]=Mod2Sum(temp1[i],Rx[i]);
                }
                memcpy(Rx,temp2,sizeof(temp2));
            }
            else
            {
                break;
            }          
        }
        cout<<"经计算校验项为：";
        int Sx[3];
        for(i=0;i<3;i++)
        {
            Sx[i]=Rx[i+4];
            cout<<Sx[i];
        }
        for(i=0;i<7;i++)
        {
            int count=0;
            for(j=0;j<3;j++)
            {
                if(Sx[j]==Translate[i][j])
                {
                    count++;
                }
            }
            if(count==3)
            {

                cout<<"\n";
                cout<<"查表得其对应第";
                cout<<Translate[i][3]<<"位错误";

            }

        }
    }
    else
    {
        for(i=0;i<7;i++)
        {
            int Sx[3];
            Sx[i]=Gx[i+4];
            cout<<Sx[i];
        }

    }   
    // for(i=0;i<7;i++)
    // {
    //     cout<<Rx[i];
    // }
    // cout<<"\n";
    cout<<"\n";
}
int FindHighest(int *Pur)
{
    int res=6,count=0;
    while (count<7)
    {
        if(Pur[count]==1)
        {
            res=count;
            break;
        }
        else
        {
            count++;
        }      
    }
    return res;
    
}
int Mod2Sum(int a,int b)
{
    if(a==b)return 0;
    else
    {
        return 1;
    }   
}