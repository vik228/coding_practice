
#include <iostream>
#include <cstdio>
#include  <queue>
using namespace std;
struct node
{
	node *left, *right;
	int data;
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
	else if (root->data > data)
	{
		root->left = makeTree (root->left, data);
	}
	else
		root->right = makeTree (root->right, data);
	return root;
}
int main()
{
	int n;
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int val;
		root = makeTree (root, scanf ("%d",&val));
	}


}
