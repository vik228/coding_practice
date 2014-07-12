#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> input;
int bsearch (int v1[], int l, int r, int key)
{
	//cout << "hiii\n";
	int m;
	while (r - l > 1)
	{
		//cout << l << " " << r << "\n";
		m = l + (r-l)/2;
		(v1[m] >= key ? r : l) = m;
	}
	return r;
}
int createLIS ()
{
	//cout << "hii\n";
	int temp[input.size() + 1];
	temp[0] = input[0];
	int len = 1;
	for (int i = 1; i < input.size(); i++)
	{
		//cout << input[i] << " ";
		if (input[i] < temp[0])
			temp[0] = input[i];
		else if (input[i] > temp[len-1])
		{
			temp[len++] = input[i];
		}
		else
		{
			temp[bsearch (temp, 0, len-1, input[i])] = input[i];
		}
	}
	/*
	for (int i = 0; i < len; i++)
	{
		cout << temp[i] << " ";
	}
	cout << "\n";
	*/
	return len;
}
int main()
{
	int N;
	scanf ("%d",&N);
	int val;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&val);
		input.push_back (val);
	}
	printf ("%d\n",createLIS());
	return 0;
}
