#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int compCount = 0;
int partition (int A[],int p,int r)
{
	int x = A[p];
	int q = p;
	for (int s = p + 1; s <= r; s++)
	{
		compCount++;
		if (A[s] < x)
		{
			q++;
			int temp = A[q];
			A[q] = A[s];
			A[s] = temp;
		}
	}
	int temp = A[q];
	A[q] = A[p];
	A[p] = temp;
	return q;
}

void quickSort(int A[],int p,int r)
{
	if(r > p)
	{
		int i = r;
		//cout << i << "\n";
		int temp = A[i];
		A[i] = A[p];
		A[p] = temp;
		int q = partition (A,p,r);
		quickSort (A,p,q-1);
		quickSort (A,q,r);

	}
}
int main()
{
	int n;
	int k;
	cin >> n;
	//cin >> k;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	quickSort(A,0,n-1);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
	cout << compCount << "\n";
	cout << "\n";
}
