#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int parent[100];
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
void printAncestor (node* root, int n)
{
}
int main()
{
	int n;
	scanf ("%d",&n);
	node* root = NULL;
	while (n--)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);

	}
	printAncestor (root, n);
}
