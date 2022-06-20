#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<ctime>
#include<fstream>
using namespace std;
int Data[1000000 + 10];
int temp[1000000 + 10];
void merge(int elem[], int lo, int hi, int mid)
{
    int i = lo, j = mid + 1;
    memset(temp, 0, sizeof(int) * 10);
    int count = 0;
    while (i <= mid && j <= hi)
    {
        if (elem[i] <= elem[j])
        {
            temp[count] = elem[i];
            count++;
            i++;
        }
        else
        {
            temp[count] = elem[j];
            count++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[count] = elem[i];
        count++;
        i++;
    }
    while (j <= hi)
    {
        temp[count] = elem[j];
        count++;
        j++;
    }
    int k, n;
    n = 0;
    for (k = lo; k <= hi; k++)
    {
        elem[k] = temp[n++];
    }
}
void MergeSort(int elem[], int lo, int hi)
{
    if (lo >= hi)return;
    else
    {
        int mid = (lo + hi) / 2;
        MergeSort(elem, lo, mid);
        MergeSort(elem, mid + 1, hi);
        merge(elem, lo, hi, mid);
    }
}
void GetNum()
{
    memset(Data, 0, sizeof(int) * 1000010);
    ifstream Myfile("D:\\sortdata\\9.txt");
    string number;
    int i = 0;
    while (getline(Myfile, number))
    {
        stringstream ss;
        ss << number;
        int temp;
        ss >> temp;
        Data[i++] = temp;
    }
}
int main()
{
    GetNum();
    clock_t start, end;
    start = clock();
    MergeSort(Data, 0, 999999);
    end = clock();
    for (int i = 0; i < 999999; i++)
    {
        printf("%d ", Data[i]);
    }
    printf("\n\n%d", end - start);
}