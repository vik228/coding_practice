#include <iostream>
#include <cstdio>
int tree[17];
using namespace std;
void update (int idx, int val)
{
	while (idx <= 16)
	{
		cout << "Updating at index " << idx << "\n";
		tree[idx]+= val;
		idx+= (idx & -idx);
	}
}
int query (int idx)
{
	int ret_val = 0;
	while (idx > 0)
	{
		cout << "Processing ur query at " << idx << "\n";
		ret_val+= tree[idx];
		idx-= idx & -idx;
	}
	return ret_val;
}
int read_single (int idx)
{
	cout << "You requested for the frequency at " << idx << "\n";
	int sum = tree[idx];
	if (idx > 0)
	{
		int z = idx - (idx & -idx);
		idx--;
		while (idx != z)
		{
			cout << "Subtracting tree[" << idx << "] " << "to get the actual sum " << "\n";
			sum-= tree[idx];
			idx-= (idx & -idx); 
		}
	}
	return sum;
}
int main()
{
	update (3,10);
	//update (7, -10);
	cout << query (4) << "\n";
	return 0;
	

}
