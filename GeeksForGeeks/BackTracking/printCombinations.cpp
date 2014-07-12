#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void printCombinations (int A[], int data[], int r, int idx, int s, int t)
{
	if (idx == r)
	{
		for (int i = 0; i < idx; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s; i <= t; i++)
	{
		cout << "placing data at " << i << " in array at " << idx << "\n";
		data[idx] = A[i];
		printCombinations (A, data, r, idx+1, s+1, t);
	}
}
int main()
{
	int A[5] = {1,2,3,4,5};
	int data[3];
	memset (data, 0, sizeof (data));
	printCombinations(A, data, 3,0,0,4);
	return 0;
}
