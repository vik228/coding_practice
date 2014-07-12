#include <iostream>
#include <cstdio>
using namespace std;
#define N1 9
#define N2 10
int heap[N2];
void percolate_down(int i)
{
	//cout << i << "\n";
	int tmp = heap[i];
	//cout << tmp << "\n";
	int p = 2*i;
	int child;
	while (p <= N1)
	{
		//cout << p << "\n";
		child = 2*i;
		if (child <= N1 and heap[child + 1] < heap[child])
			child++;
		if (heap[child] < tmp)
		{
			heap[i] = heap[child];
			heap[child] = tmp;
			i = child;
			p = 2*i;
		}
		else
		{
			i = child;
			p = 2*i;
			break;
		}
	}
}
void build_heap (int a[])
{
	heap[0] = 0;
	for (int i = 1; i <= N1; i++)
	{
		heap[i] = a[i-1];
	}
	for (int i = N1/2; i > 0; i--)
	{
		percolate_down(i);
	}
}
/*
void heap_sort(int a[])
{
	build_heap(a);
	int m = N2;
	while (m >= 2)
	{
		int tmp = heap[1];
		heap[1] = heap[m];
		heap[m] = tmp;
		m--;
		percolate_down(1);

	}
}
*/
int main()
{
	int a[9] = {19,2,9,3,4,1,8,7,5};
	build_heap(a);
	for (int i = 1;i < 9; i++)
		cout << heap[i] << " ";
	cout << "\n";
		return 0;
}
