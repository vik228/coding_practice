#include <iostream>
#include <cstdio>
using namespace std;
struct Point
{
	int x, y;
};
bool isOnSegment (Point p, Point q, Point r)
{
	if ((q.x <= max (p.x, r.x)) and (q.x >= min (p.x, r.x)) and (q.y <= max (p.y, r.y)) and (q.y >= min (p.y, r.y)))
		return true;
	return false;
}
int getOrientation (Point p, Point q, Point r)
{
	int val = (q.y - p.y)*(r.x-q.x) - (q.x-p.x)*(r.y - q.y);
	if (val == 0)
		return 0;
	else 
		return (val > 0)? 1 : 2;
}
bool doIntersect (Point p1, Point q1, Point p2, Point q2)
{
	int o1 = getOrientation (p1, q1, p2);
	int o2 = getOrientation (p1, q1, q2);
	int o3 = getOrientation (p2, q2, p1);
	int o4 = getOrientation (p2, q2, q1);
	if ((o1 != o2) and (o3 != o4))
		return true;
	if (o1 == 0)
		if (isOnSegment (p1, p2, q1))
			return true;
	if (o2 == 0)
		if (isOnSegment (p1, q2, q1))
			return true;
	if (o3 == 0)
		if (isOnSegment (p2, p1, q2))
			return true;
	if (o4 == 0)
		if (isOnSegment (p2, q1, q2))
			return true;
	return false;
}
int main()
{
	Point p1, q1, p2, q2;
	cout << "Enter the coordinates\n";
	cin >> p1.x >> p1.y >> q1.x >> q1.y >> p2.x >> p2.y >> q2.x >> q2.y;
	if (doIntersect (p1, q1, p2, q2))
		cout << "YES\n";
	else
		cout << "NO\n";

}
