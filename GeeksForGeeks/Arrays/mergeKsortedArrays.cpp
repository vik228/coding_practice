#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[10];
vector <int> ans;
int idx[10];
struct heap
{
	int l_no;
	int val;
};
bool comp (heap &a, heap &b)
{
	return (a.val > b.val);
}
void merge (int k, int n)
{
	vector <heap> v1;
	for (int i = 0; i < k; i++)
	{
		//vector <int> v1;
		heap h1;
		h1.l_no = i;
		h1.val = v[i][0];
		v1.push_back (h1);
	}
	make_heap (v1.begin(), v1.end(), comp);
	while (!v1.empty())
	{
		cout << v1.size() << "\n";
		heap h1 = v1.front();
		ans.push_back (h1.val);
		idx[(h1.l_no)]++;
		pop_heap (v1.begin(), v1.end(), comp);
		v1.pop_back ();
		heap h2;
		h2.val = v[h1.l_no][idx[h1.l_no]];
		h2.l_no = h1.l_no;
		v1.push_back (h2);
		push_heap (v1.begin(), v1.end(), comp);
	}




}
int main()
{
	int k, n;
	scanf ("%d%d",&k,&n);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val;
			scanf ("%d",&val);
			v[i].push_back (val);
		}
	}
	merge (k, n);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";

}
