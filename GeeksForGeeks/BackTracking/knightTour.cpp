#include <iostream>
#include <cstdio>
using namespace std;
int sol[8][8];
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
bool isSafe (int x, int y)
{
	if ((x < 0 and x >= 8) or (y < 0 and y >= 8) or sol[x][y] != -1)
		return false;
	return true;
}
bool traverse (int x, int y, int move)
{
	if (move == 64)
		return true;
	for (int j = 0; j < 8; j++)
	{
		int x_coord = x + xMove[j];
		int y_coord = y + yMove[j];
		if (isSafe (x_coord, y_coord))
		{
			sol[x_coord][y_coord] = move;
			if (traverse (x_coord, y_coord, move+1))
				return true;
			else
				sol[x_coord][y_coord] = -1;
		}

	}
	return false;
}
int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			sol[i][j] = -1;
	}
	sol[0][0] = 0;
	if (traverse (0, 0, 1))
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << sol[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	return 0;
}
