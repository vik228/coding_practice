#include <iostream>
#include "Heap.cpp"
#include "treeNode.cpp"
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
	string s;
	char ch;
	cin >> ch;
	while (!cin.eof())
	{
		s += ch;
		cin >> ch;
	}
	//cout << s;
	//exit(0);
	int count[27];
	memset(count,0,sizeof(count)); 
	for (int i = 0; i < s.length();i++)
	{
		cout << s[i] << " is " << (int)(s[i] - 'a') << "\n";
		count[s[i] - 'a'] += 1;
	}
	#ifdef DEBUG
		for (int i = 0; i < s.length(); i++)
		{
			cout << "The count of " << s[i] << " " << count[s[i] - 'a'] << "\n";
		}
	#endif
	TreeNode <char,int>* t1;
	Heap < TreeNode<char,int> > pq;
	for (int i = 0; i < s.length();i++)
	{
		t1 = new TreeNode <char, int>(&s[i],&count[s[i] - 'a']);
		pq.insert(t1);
	}
	return 0;
}
