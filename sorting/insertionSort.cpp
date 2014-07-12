#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[] = {2,4,1,-1,0};
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0;j < i; j++)
		{
			if (a[j] > a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
			
		}
	}
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";

}
