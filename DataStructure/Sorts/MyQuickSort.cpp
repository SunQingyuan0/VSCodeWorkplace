// #include<cstdio>
// #include<cstdlib>
// #include<iostream>
// using namespace std;
// int partition(int lo,int hi,int *elem)
// {
//     int pivot=elem[lo];
//     while(lo<hi)
//     {
//         while (lo<hi)
//         {
//             if(elem[hi]>pivot)hi--;
//             else
//             {
//                 elem[lo++]=elem[hi];
//                 break;
//             }
//         }
//         while (lo<hi)
//         {
//             if(elem[lo]<pivot)lo++;
//             else
//             {
//                 elem[hi--]=elem[lo];
//                 break;
//             }   
//         }
//     }
//     elem[lo]=pivot;
//     return lo;

// }
// void QuickSort(int lo,int hi,int *elem)
// {
//     if(hi-lo<2)return;
//     int mi=partition(lo,hi,elem);
//     QuickSort(lo,mi,elem);
//     QuickSort(mi+1,hi,elem);
// }
// int main()
// {
//     int test[10];
//     for(int i=0;i<10;i++)
//     {
//         cin>>test[i];
//     }
//     QuickSort(0,9,test);
//     for(int i=0;i<10;i++)
//     {
//         printf("%d ",test[i]);
//     }
// }
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
void quickSort(int left, int right, int* arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left]; 
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);
	quickSort(i + 1, right, arr);
}
void GetNum()
{
    memset(Data, 0, sizeof(int) * 1000010);
    ifstream Myfile("D:\\sortdata\\1.txt");
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
    quickSort( 0, 999999,Data);
    end = clock();
    for (int i = 0; i < 999999; i++)
    {
        printf("%d ", Data[i]);
    }
    printf("\n\n%d", end - start);
}