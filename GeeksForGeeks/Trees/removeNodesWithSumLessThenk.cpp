#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
node* makeTree (node *root, int data)
{
	if (root == NULL)
	{
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > data)
		root->left = makeTree (root->left, data);
	else
		root->right = makeTree (root->right, data);
	return root;
}
node* solve (node *root, int k, int sum)
{
	if (root == NULL)
		return NULL;
	sum += root->data;
	root->left = solve (root->left, k, sum);
	root->right = solve (root->right, k, sum);
	if (root->left == NULL and root->right == NULL)
	{
		if (sum < k)
		{
			cout << "sum is " << sum << " removing " << root->data << "\n";
			delete (root);
			root = NULL;
		}
	}
	return root;

}
void inorder (node *root)
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
	int d;
	node *root = NULL;
	while (n--)
	{
		scanf ("%d",&d);
		root = makeTree (root, d);
		
	}
	int k;
	cin >> k;
	root = solve (root,k,0);
	inorder (root);
	cout << "\n";
	return 0;
}
