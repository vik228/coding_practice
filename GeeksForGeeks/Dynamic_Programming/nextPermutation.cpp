#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int input[100];
bool nextPermutation (int n)
{
	//cout << "hiii\n";
	int idx, idx2;
	bool found = false;
	for (int i = n-1; i >= 0; i--)
	{
		if (input[i] > input[i-1])
		{
			idx = i-1;
			found = true;
			break;
		}
	}
	//cout << idx << "\n";
	if (found)
	{
		for (int i = n-1; i > idx; i--)
		{
			if (input[i] > input[idx])
			{
				idx2 = i;
				break;
			}
		}
		//cout << idx2 << "\n";
		int temp = input[idx];
		input[idx] = input[idx2];
		input[idx2] = temp;
		int i = idx + 1;
		int j = n-1;
		while (j-i >= 1)
		{
			//cout << "hii\n";
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
		return true;
	}
	return false;
}
int main()
{
	int n; 
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&input[i]);
	}
	sort (input, input + n);
	while (nextPermutation (n))
	{
		for (int i = 0; i < n; i++)
			cout << input[i];
		cout << "\n";
	}
	return 0;
}
