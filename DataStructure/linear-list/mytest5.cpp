#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
struct student
{
    char number[7];
    char name[9];
    int grade;
};
bool cmp1(student a,student b)
{
    return strcmp(a.number,b.number)<0;
}
bool cmp2(student a,student b)
{
    if(strcmp(a.name,b.name)==0)
    {
        return cmp1(a,b);
    }
    else
    {
        return strcmp(a.name,b.name)<0;
    }  
}
bool cmp3(student a,student b)
{
    if(a.grade==b.grade)
    {
        return cmp1(a,b);
    }
    else
    {
        return a.grade<b.grade;
    }
    
}
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    int i;
    student data[105];
    student *p=data;
    for(i=0;i<n;i++)
    {
        memset(data[i].name,0,sizeof(char)*9);
        scanf("%s%s%d",data[i].number,data[i].name,&data[i].grade);
    }
    switch (c)
    {
    case 1:sort(data,data+n,cmp1);
        break;
    case 2:sort(data,data+n,cmp2);
        break;  
    default:sort(data,data+n,cmp3);
        break;
    }
    for(i=0;i<n;i++)
    {
        printf("%s %s %d\n",data[i].number,data[i].name,data[i].grade);
    }
}