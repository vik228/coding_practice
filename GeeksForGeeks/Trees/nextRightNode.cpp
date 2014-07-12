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
node* getNextRightNode (node* root, int key)
{
	if (root == NULL)
		return NULL;
	int level = 0;
	queue<node*> Q;
	queue <int> q1;
	Q.push(root);
	q1.push(level);
	while (!Q.empty())
	{
		node* n1 = Q.front();
		Q.pop();
		int lvl = q1.front();
		q1.pop();
		if (n1->data == key)
		{
			if (!q1.empty() or q1.front() != lvl)
				return NULL;
			return Q.front();
		}
		if (n1->right != NULL)
		{
			Q.push(n1->right);
			q1.push(lvl+1);

		}
		if (n1->left != NULL)
		{
			Q.push(n1->left);
			q1.push(lvl+1);
		}
	}
	return NULL;


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
