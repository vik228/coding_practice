#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
int sum = 0;
node* makeTree (node* root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		//return root;
	}
	else if (root->data > data)
		root->left = makeTree (root->left, data);
	else
		root->right = makeTree (root->right, data);
	return root;
}
node* add (node* root)
{
	if (root == NULL)
		return NULL;
	root->right = add (root->right);
	cout << sum << "+" << root->data << "\n";
	sum = sum+root->data;
	root->data = sum;
	root->left = add (root->left);
	return root;

}
void inorder (node* root)
{
	if (root != NULL)
	{
		inorder (root->left);
		cout << root->data << " ";
		inorder (root->right);
	}

}
int main()
{
	int n;
	scanf ("%d",&n);
	node *root = NULL;
	int data;
	while (n--)
	{
		cin >> data;
		root = makeTree (root, data);
	}
	inorder (root);
	cout << "\n";
	root = add (root);
	inorder (root);
	return 0;
}
