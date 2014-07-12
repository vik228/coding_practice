#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
node* create (node* root, int data)
{
	root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}
int findHeight (node* root)
{
	queue <node*> q;
	q.push (root);
	int height = 0;
	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			return height;
		height++;
		while (nodeCount > 0)
		{
			node *a = q.front();
			q.pop();
			if (a->left != NULL)
				q.push (a->left);
			else if (a->right != NULL) 
				q.push (a->right);
			nodeCount--;
		}
	}
}
int main()
{
	node *root = create (root, 1);
	root->left = create (root->left, 2);
	root->right = create (root->right, 3);
	root->left->left = create (root->left->left, 4);
	root->left->right = create (root->left->right, 5);
	cout<< findHeight (root) << "\n";
	return 0;
}
