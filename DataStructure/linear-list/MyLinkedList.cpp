#include<iostream>
#include<string>
using namespace std;
char c[26];

void  print(int i,int n)
{
	if (i == n)
	{
		cout << c << endl;
	}
	else
	{
		for (int j = 0; j < n; j++,i--)
		{
			c[i] = 'A' + j;
			i++;
			print(i, n);
		}
	}
}

int main()
{
	cout << "number:" << endl;
	int n;                             //n<10
	cin >> n;

	cout << "------------" << endl << "result:" << endl;
	print(0,n);
}
