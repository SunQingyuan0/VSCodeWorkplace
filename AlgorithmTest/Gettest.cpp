#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;
void GetNum(int n,ofstream &outfile)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        outfile<<rand()%n<<endl;
    }
}
int main()
{
    ofstream outfile("D:\\Datafile\\10.txt");
    if(!outfile){
    cout << "Unable to open otfile";
        exit(1);
}
    GetNum(1000000,outfile);
}