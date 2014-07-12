#include <cstdio>
#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
node* makeTree (node* root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data < data)
		root->right = makeTree (root->right, data);
	else if (root->data > data)
		root->left = makeTree (root->left, data);
	return root;
}
bool leavesAtSameLevel (node* root, int* maxLevel, int level)
{
	if (root == NULL)
		return true;
	if (root->left == NULL and root->right == NULL)
	{
		if (*maxLevel == 0)
		{
			*maxLevel = level;
			return true;
		}
		else
		{
			if (level != *maxLevel)
			{
				return false;
			}
			else
				return true;
		}
	}
	return (leavesAtSameLevel(root->left, maxLevel, level+1) and leavesAtSameLevel (root->right, maxLevel, level+1));
}
int main()
{
	int N;
	scanf ("%d",&N);
	node* root = NULL;
	int maxLevel = 0;
	while (N--)
	{
		int val;
		scanf ("%d", &val);
		root = makeTree (root, val);

	}
	if (leavesAtSameLevel (root, &maxLevel, 0))
	{
		cout << "Yes\n";
	}
	else
		cout << "No\n";
	return 0;
}
