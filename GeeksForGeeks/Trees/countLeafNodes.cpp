#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
Node* create (Node* node, int data)
{
	//cout << "hii\n";
	if (node == NULL)
	{
		node = new Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (node->data < data)
	{
		node->right = create (node->right, data);
	}
	else
		node->left = create (node->left, data);
	return node;
}
int countLeaf (Node* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL and root->right == NULL)
		return 1;
	int l = countLeaf (root->left);
	int r = countLeaf (root->right);
	return (l + r);
}
int main()
{
	int n;
	scanf ("%d",&n);
	int val;
	Node* root = NULL;
	while (n--)
	{
		scanf ("%d",&val);
		root = create (root, val);
	}
	cout << countLeaf (root) << "\n";
}
