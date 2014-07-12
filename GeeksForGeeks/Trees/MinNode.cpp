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
void minNode (Node* root)
{
	if (root->left == NULL and root->right == NULL)
	{
		cout << root->data << " ";
		return;
	}
	minNode (root->left);
}
int main ()
{
	Node* root = TakeInputAndCreate ();
	//cout << minNode (root)->data << "\n";
	minNode (root);

}
