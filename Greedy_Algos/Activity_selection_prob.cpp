#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct s
{
	int start;
	int end;
}s1[100010];
bool myfunction (s a, s b)
{
	return (a.end < b.end);
	
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		for (int i = 0; i < n; i++)
		{
			cin >> s1[i].start >> s1[i].end;
		}
		sort (s1,s1+n,myfunction);
		int prev = 0;
		int cnt = 0;
		int ans;
		for (int i = 0; i < n; i++)
		{
			//cout << s1[i].start << " -> " << s1[i].end << "\n";
			if (s1[i].start > s1[prev].end)
			{
				cnt++;
				prev = i;
			}
		}
		ans = n - cnt;
		printf ("%d\n",cnt);

	}
	return 0;
}
