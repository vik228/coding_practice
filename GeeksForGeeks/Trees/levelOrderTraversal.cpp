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
void levelOrderTraversal (Node* u)
{
	queue <Node*> q;
	q.push(u);
	while (!q.empty())
	{
		Node* v = q.front();
		cout << v->data << " ";
		q.pop();
		if (v->left != NULL)
			q.push (v->left);
		if (v->right != NULL)
			q.push (v->right);
	}
}
int main()
{
	Node* root = TakeInputAndCreate ();
	levelOrderTraversal (root);
	return 0;
}
