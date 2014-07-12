#include <iostream>
#include <cstdio>
#include <cstdlib>
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
	else if (node->data < data)
	{
		return (create (node->right, data));
	}
	else
	{
		return (create (node->left, data));
	}
	return node;
}
int getHeight (Node* root)
{
	if (root == NULL)
		return 0;
	return (max (getHeight(root->left), getHeight (root->right)) + 1);
}
bool isBalanced (Node* root)
{
	if (root == NULL)
		return true;
	int height = abs (getHeight (root->left) - getHeight (root->right));
	if (height > 1)
		return false;
	else
	{
		return ((isBalanced (root->left)) and (isBalanced (root->right)));
	}
}
int main()
{
	Node* root = NULL;
	int val;
	int t = 5;
	while (t--)
	{
		scanf ("%d",&val);
		root = create (root, val);
	}
	if (isBalanced (root))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
