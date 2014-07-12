#include <iostream>
#include <cstdio>
using namespace std;
int tree[5][5];
void update (int n, int x, int y, int val)
{
	int y1;
	while (x <= n)
	{
		y1 = y;
		while (y1 <= n)
		{
			tree[x][y1]+= val;
			y1+= (y1 & -y1);
		}
		x+= (x & -x);
	}
}
int main()
{
	update (4,2,3,2);
	update (4,1,1,3);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}
}
