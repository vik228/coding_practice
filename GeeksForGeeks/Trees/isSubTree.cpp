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
bool areIdentical (Node* root1, Node* root2)
{
	if (root1 == NULL and root2 == NULL)
		return true;
	if (root1 == NULL or root2 == NULL)
		return false;
	return ((root1->data == root2->data) and (areIdentical(root1->left, root2->left)) and (areIdentical (root1->right, root2->right)));
}
bool isSubTree (Node* root1, Node* root2)
{
	if (root1 == NULL)
		return false;
	if (root2 == NULL)
		return true;
	if (areIdentical (root1, root2))
		return true;
	else
		return (isSubTree (root1->left, root2) or isSubTree (root1->right, root2));
}
int main ()
{
	Node* root1 = TakeInputAndCreate ();
	Node* root2 = TakeInputAndCreate ();
	if (isSubTree (root1, root2))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
