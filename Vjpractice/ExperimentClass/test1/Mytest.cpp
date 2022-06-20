#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<iostream>
#include<iterator>
using namespace std;
struct Unit
{
    string Name;//元素名称
    int Number;//元素数量
    Unit(string nn="",int num=0):Name(nn),Number(num){}//构造函数
};
int DealNumber(string Target,int &i)//处理数字，返回值为处理结果，同时将游标移动到下一类字符
{
    int sum=0;//初始化
    while (isdigit(Target[i]))//如果游标当前指向的字符是数字
    {
        sum=sum*10+Target[i]-'0';//更新sum变量
    }//直到遇到不是数字的字符为止
    return sum;//返回处理结果，此时游标被放置在正确的位置
}
void GetRes(string Target,map<string,int> &Data)
{
    stringstream temp1(Target);
    string Formula;//化学式
    while (getline(temp1,Formula,'+'))//以加号为界切割字符串得到化学式，对其循环处理
    {
        int Coe=1;//系数初始化
        vector<Unit> ElemStack;//存储处理的元素
        int i=0;//游标初始化
        if(isdigit(Formula[i]))
        Coe=DealNumber(Formula,i);//获取系数
        while (i<Formula.size())
        {
            if(isupper(Formula[i]))//判断大写字母
            {
                string ElemName="";
                ElemName+=Formula[i];//对该字符进行存储
                i++;//游标+1
                if(islower(Formula[i]))//判断小写字母
                {
                    ElemName+=Formula[i];//存储
                    i++;//游标+1
                }
                ElemStack.push_back(Unit(ElemName,1));//进入vector
            }
            else if(Formula[i]=='(')//判断左括号
            {
                ElemStack.push_back(Unit("(",1));//进入vector
                i++;
            }
            else if(Formula[i]==')')//判断右括号
            {
                ElemStack.push_back(Unit(")",1));
                if(i+1==Formula.size())//判断是否是最后一个字符，防止越界访问
                {
                    Formula.insert(i+1,"1");//插入数字1
                }
                if(!isdigit(Formula[i+1]))//判断在其后面有无数字
                {
                    Formula.insert(i+1,"1");//同上
                }
                i++;
            }
            else if(isdigit(Formula[i]))//判断数字
            {
                int number=DealNumber(Formula,i);//获取数字
                if(ElemStack.back().Name==")")//判断最后一个元素是否是右括号
                {//若是
                    int j=ElemStack.size()-1;//新建游标
                    ElemStack[j].Name="*";//将元素名改成特殊符号，表示已经处理过
                    while (ElemStack[--j].Name!="(")//向前回退，直到找到第一个左括号停止
                    {
                        ElemStack[j].Number*=number;//对范围内的每一个元素的数量做处理，令其乘上之前获得的数字
                    }
                    ElemStack[j].Name="*";//对左括号元素名进行修改
                }
                else//若不是
                {
                    ElemStack.back().Number*=number;//只处理最后的元素
                }
            }

        }
        for(int k=0;k<ElemStack.size();k++)//对vector中的数据进行加工，整合
        {
            if(ElemStack[k].Name=="*")continue;//表示括号，无意义，跳过
            Data[ElemStack[k].Name]+=ElemStack[k].Number*Coe;//利用元素名作为key值寻找，对同名元素，先乘系数再合并
        }
    }
}
bool Judge(map<string,int> Data1,map<string,int> Data2)
{
    if(Data1.size()!=Data2.size())return false;//若元素数量不相等，直接判定为否
    map<string,int>::iterator p;//建立迭代器
    for(p=Data1.begin();p!=Data1.end();p++)//令迭代器指向统计化学反应方程式左端元素的容器，进行对其进行遍历
    {
        if(Data2[p->first]!=p->second)return false;//以迭代器的key值当做右端的容器的key值进行，通过这种方式来实现左右两端元素的直接对应，进行二者数量的对比
    }//到这一步有两种情况，一种是左右元素的种类都是相同的，这种情况显然可以处理
    //另一种情况是元素种类有不同的情况，如果出现这种情况
    //左端至少有一种元素与右端不同，右端同样如此，依据上方的式子来判断，也可以判断出来
    return true;
}//可见，由于采用了map，比较的过程大大简化，可以直接访问并比较左右两端的同名元素而不必再去查找
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        string Target,Left,Right;
        map<string,int> Data1,Data2;//变量定义
        cin>>Target;//输入
        stringstream temp(Target);
        getline(temp,Left,'=');//切割左侧
        getline(temp,Right);//切割右侧
        GetRes(Left,Data1);
        GetRes(Right,Data2);
        if(Judge(Data1,Data2)) printf("Y\n");
        else printf("N\n");
    }
}