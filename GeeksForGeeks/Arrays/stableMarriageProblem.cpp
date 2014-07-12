#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector <int> pref[10];
bool woman[4];
map <int, int> m1;
void stableMarriage ()
{
	queue <int> Q;
	for (int i = 0; i < 4; i++)
		Q.push(i);
	while (!Q.empty())
	{
		int i = Q.front();
		Q.pop();
		for (int j = 0; j <pref[i].size(); j++)
		{
			if (!woman[pref[i][j]])
			{
				m1[pref[i][j]] = i;
				woman[pref[i][j]] = true;
				break;
			}
			else
			{
				int t = m1[pref[i][j]];
				for (int k = 0; k < pref[pref[i][j]].size(); k++)
				{
					if (pref[pref[i][j]][k] == t)
						break;
					else if (pref[pref[i][j]][k] == i)
					{
					 	m1[pref[i][j]] = i;
						Q.push(t);
						break;
					}
				}
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int i = 0; i < 4; i++)
		{
			int val;
			scanf ("%d",&val);
			pref[i].push_back (val);
		}
	}
	stableMarriage();
	map<int, int>::iterator it;
	for (it = m1.begin(); it != m1.end(); it++)
	{
		cout << (it->first) << "->" << (it->second) << "\n";
	}

}
