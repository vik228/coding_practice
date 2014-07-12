#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Point
{
	int x, y;
}points[100];
int next[100];
int getOrientation (Point p, Point q, Point r)
{
	int val = (q.y - p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	if (val == 0)
		return 0;
	else 
		return (val > 0) ? 1 : 2;
}
void convexHull (int n)
{
	if (n < 3)
		return;
	memset (next, -1, sizeof (next));
	int l = 0;
	for (int i = 1; i < n; i++)
	{
		if (points[i].x < points[l].x)
			l = i;
	}
	int p = l, q;
	do
	{
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
			if (getOrientation (points[p], points[i], points[q]) == 2)
				q = i;
		}
		next[p] = q;
		p = q;
	}while (p != l);
	
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}
	convexHull (n);
	for (int i = 0; i < n; i++)
	{
		if (next[i] != -1)
			cout << "( " << points[next[i]].x << "," << points[next[i]].y << ")" << "\n";
	}
}
