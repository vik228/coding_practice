#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
bool graph[10][10];
int r, c;
bool visited[10][10];
void dfs (int i, int j)
{
	stack < pair<int, int> > s1;
	s1.push (make_pair(i, j));
	while (!s1.empty())
	{
		pair <int, int> p1 = s1.top();
		s1.pop();
		int x = p1.first;
		int y = p1.second;
		visited[x][y] = true;
		for (int cx = -1; cx <= 1; cx++)
		{
			for (int cy = -1; cy <= 1; cy++)
			{
				int c_x = cx + x;
				int c_y = cy + y;
				if (c_x < 0 or c_x >= r)
					continue;
				if (c_y < 0 or c_y >= c)
					continue;
				if (!visited[c_x][c_y] and graph[c_x][c_y])
				{
					s1.push(make_pair(c_x, c_y));
					visited[c_x][c_y] = true;
				}
			}
		}
	}

}
int main()
{
	scanf ("%d%d",&r,&c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf ("%d",&graph[i][j]);
		}
	}
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (!visited[i][j] and graph[i][j])
			{
				dfs (i, j);
				count++;
			}
		}
	}
	printf ("%d\n",count);
}
