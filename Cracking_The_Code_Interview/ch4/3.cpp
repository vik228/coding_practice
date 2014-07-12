#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
Node* root = NULL;
Node* createBST (Node* root, int val)
{
	cout << val << "\n";
	if (root == NULL)
	{
		root = new Node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if (val < root->data)
	{
		root->left = createBST (root->left, val);
	}
	else 
	{
		root->right = createBST (root->right, val);
	}
	return root;
}
void inorder (Node* root)
{
	if (root != NULL)
	{
		inorder (root->left);
		cout << root->data << " ";
		inorder (root->right);
	}
}
void BST (int a[], int lo, int hi)
{
	if (hi < lo)
		return;
	int mid = (hi+lo)/2;
	root = createBST (root, a[mid]);
	BST (a, lo, mid-1);
	BST (a, mid+1, hi);
}
int main()
{
	int arr[5] = {20, 30, 60, 80, 90};
	BST (arr, 0, 4);
	inorder (root);
}
