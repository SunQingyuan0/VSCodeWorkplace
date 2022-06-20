#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
void merge(int *A, int p, int q, int r) {
	int n1 = q - p, n2 = r - q;
	int *L = new int[n1], *R = new int[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = A[p+i];
	for (int i = 0; i < n2; ++i)
		R[i] = A[q+i];
	int i = 0, j = 0;
	int k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < n1)
		A[k++] = L[i++];
	while (j < n2)
		A[k++] = R[j++];
	delete [] L;
	delete [] R;
}
void merge_sort(int *a, int p, int r) {
	if (p < r - 1) {
		int q = p + (r - p)/2;
		merge_sort(a, p, q);
		merge_sort(a, q, r);
		merge(a, p, q, r);
	}
}
int main()
{
	srand(time(NULL));
	int n;
	while (cin >> n) {
		int a[n];
		for (int i = 0; i < n; ++i)
			a[i] = rand() % n;
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		merge_sort(a, 0, n);
		for (int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
}