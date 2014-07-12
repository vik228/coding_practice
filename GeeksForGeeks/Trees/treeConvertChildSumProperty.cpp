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
void convertChildSumProperty (node* root)
{
	if (root == NULL)
		return;
	convertChildSumProperty (root->left);
	convertChildSumProperty (root->right);
	int lData = 0, rData = 0; 
	if (root->left)
		lData = root->left->data;
	if (root->right)
		rData = root->right->data;
	int sumChild = lData + rData;
	int rootData = root->data;
	if (root->left or root->right)
	{
		if (sumChild < rootData)
		{
			if (root->left)
				root->left->data += (rootData-sumChild);
			else if (root->right)
				root->right->data += (rootData - sumChild);
		}
		else
		{
			root->data += (sumChild-rootData);
		}
	}


		
}
void inorder (node* root)
{
	if (root)
	{
		inorder (root->left);
		cout << root->data << " ";
		inorder (root->right);
	}
}
int main()
{
	int n;
	node* root = NULL;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);
	}
	inorder (root);
	cout << "\n";
	convertChildSumProperty (root);
	inorder (root);


}
