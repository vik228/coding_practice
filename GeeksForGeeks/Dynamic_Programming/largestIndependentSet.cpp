#include <iostream>
#include <cstdio>
using namespace std;
struct Node 
{
	int data, liss;
	Node *left, *right;
};
Node* create (Node* root, int data)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data < data)
	{
		root->right = create (root->right, data);
	}
	else
		root->left = create (root->left, data);
	return root;
}
int getLIS (Node* root)
{
	if (root == NULL)
		return 0;
	if (root->liss)
		return root->liss;
	if (root->left == NULL and root->right == NULL)
		return (root->liss = 1);
	int val1 = getLIS (root->left) + getLIS (root->right);
	int val2 = 1;
	if (root->left)
	{
		val2 += getLIS (root->left->left) + getLIS (root->left->right);
	}
	if (root->right)
	{
		val2 += getLIS (root->right->left) + getLIS (root->right->right);
	}
	return (root->liss = max (val1, val2));
}
int main()
{
	int n;
	scanf ("%d",&n);
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		root = create (root, val);

	}
	cout << getLIS (root) << "\n";
}
