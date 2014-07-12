#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
struct ret_val
{
	int sum;
	bool val;
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
Node* TakeInputAndCreate ()
{
	int n;
	int t;
	Node* root = NULL;
	scanf ("%d",&n);
	while (n--)
	{
		scanf ("%d",&t);
		root = create (root, t);
	}
	return root;
}
ret_val isSumTree (Node* root)
{
	if (root == NULL)
	{
		ret_val c;
		c.sum = 0;
		c.val = true;
		return c;
	}
	if (root->left == NULL and root->right == NULL)
	{
		ret_val a;
		a.sum = root->data;
		a.val = true;
		return a;
	}
	ret_val left, right;
	left = isSumTree (root->left);
	right = isSumTree (root->right);
	ret_val b;
	if ((left.sum + right.sum) == root->data and (left.val and right.val))
	{
		b.sum = root->data + left.sum + right.sum;
		b.val = (left.val and right.val)
	}
	else
	{

		b.sum = root->data;
		b.val = false;
	}
}
int main()
{
	Node* root = TakeInputAndCreate ();
	ret_val v1 = isSumTree (root);
	if (v1.val)
		cout << "YES\n";
	else
		cout << "NO\n";
}
