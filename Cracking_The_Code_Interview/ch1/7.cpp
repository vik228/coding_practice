#include <iostream>
#include <cstdio>
using namespace std;
void change_to_zero(int input[][10], int R, int C)
{

	bool row[10];
	bool col[10];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (input[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (row[i] or col[j])
			{
				input[i][j] = 0;
			}
		}
	}
}
int main()
{
	int R, C;
	scanf ("%d%d",&R,&C);
	int a;
	int row_zero, col_zero;
	int input[10][10];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf ("%d",&a);
			input[i][j] = a;
		}
	}
	change_to_zero (input, R, C);
	for (int i = 0; i < R; i++)
	{
		cout << "\n";
		for (int j = 0; j < C; j++)
		{
			cout << input[i][j] << "\t";
		}
	}
	cout << "\n";
}
