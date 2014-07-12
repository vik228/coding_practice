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
int deepestOddLevelLeafNode (node* root, int level)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL and root->right == NULL and level % 2 == 1)
		return level;
	return (max (deepestOddLevelLeafNode (root->left, level+1), deepestOddLevelLeafNode (root->right, level+1)));
}
int main()
{
	int n, val;
	scanf ("%d",&n);
	node* root = NULL;
	while (n--)
	{
		scanf ("%d",&val);
		root = makeTree (root, val);

	}
	int maxLevel = 0;
	node* lNode = NULL;
	cout << deepestOddLevelLeafNode (root, 0) << "\n";

}
