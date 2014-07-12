#include <iostream>
using namespace std;
int main()
{
	int a[] = {0,2,4,0,5};
	int count;
	for (int i = 0; i < 5; i++)
	{
		count = i;
		for (int j= i + 1; j < 5; j++)
		{
			if(a[j] < a[i])
			{
				count = j;
			}

		}
		int temp = a[count];
		a[count] = a[i];
		a[i] = temp;
	}
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";

}
