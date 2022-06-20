#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;
#define N 10000000
int Data[N];
void QuickSort(int left, int right, int* arr)
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
	QuickSort(left, i - 1, arr);
	QuickSort(i + 1, right, arr);
}
int partition(int A[], int low, int high)
{
	int pivot = A[low];
	while (low < high){
		while (low < high && A[high] >= pivot){
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot){
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
int r = 5;
int Select(int A[], int low, int high, int k)
{
	int r_group = ceil((high - low + 1)*1.0 / r);
	for (int i = 1; i <= r_group; ++i) {
		sort(&A[low + (i - 1)*r], &A[(low + i*r - 1) > high ? high : (low + i*r - 1)]);
		swap(A[low + i - 1], A[low + (i-1)*r + r / 2]);
	}
	sort(&A[low], &A[low + r_group]);
	swap(A[low], A[r_group / 2]);
	int cur = partition(A, low, high);
	if (cur == k-1){
		return A[cur];
	}
	else if (cur < k){
		return Select(A, cur + 1, high, k);
	}
	else{
		return Select(A, low, cur - 1, k);
	}
}
int Select2(int A[], int low, int high, int k)
{
    QuickSort(low,high,A);
    return A[k-1];
}
void GetNum(int n)
{
    srand(time(NULL));
    memset(Data,0,N*sizeof(int));
    for(int i=0;i<n;i++)
    {
        Data[i]=rand()%n;
    }
}
void TestRun(int n,int &a,int &b)
{
    GetNum(n);
    srand(time(NULL));
    int k=(rand()%n)+1;
    clock_t start1,end1,start2,end2;
    start1=clock();
    int test=Select(Data,0,n-1,k);
    end1=clock();
    start2=clock();
    Select2(Data,0,n-1,k);
    end2=clock();
    printf("%d %d\n",end1-start1,end2-start2);
    a=end1-start1;
    b=end2-start2;
}
void GetRes()
{
    int TestN[10]={1000,2000,5000,10000,20000,50000,100000,200000,500000,1000000};
    int sum1=0,sum2=0;
    ofstream of1("D:\\Datafile\\Data1.txt");
    ofstream of2("D:\\Datafile\\Data2.txt");
    for(int j=0;j<10;j++)
    {
        int a,b;
        for(int i=0;i<100;i++)
        {
            TestRun(TestN[j],a,b);
            sum1+=a,sum2+=b;
        }
        double res1=sum1/(double)100;
        double res2=sum2/(double)100;
        of1<<res1<<endl;
        of2<<res2<<endl;
    }
    of1.close();
    of2.close();
}
int main()
{
    GetRes();
	return 0;
}
