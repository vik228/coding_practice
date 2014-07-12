#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
node *a;
node* makeTree (node* root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (root->data > data)
	{
		root->left = makeTree (root->left, data);
	}
	else
		root->right = makeTree (root->right, data);
	return root;
}
void convert (node* root)
{
	cout << "hii\n";
	if (root == NULL)
		return;
	if (root->left == NULL and root->right == NULL)
	{
		if (a == NULL)
		{
			a = root;
		}
		else
		{
			a->right = root;
			root->left = a;
			a = root;
		}
		return;
	}
	convert (root->left);
	convert (root->right);
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
int main ()
{

	a = NULL;
	node* root = NULL;
	int n = 5;
	int b;
	while (n--)
	{
		cin >> b;
		root = makeTree (root, b);
	}
	inorder (root);
	//cout << "\n";
	convert (root);
	cout << "hii\n";
	while (a != NULL)
	{
		cout << (a->data) << " ";
		a = a->left;
	}

}
