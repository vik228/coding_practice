#include <iostream>
#include <cstdio>
#include  <queue>
#include <cstdlib>
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
int getHeight (node* root)
{
	if (root == NULL)
		return 0;
	return (max (getHeight (root->left), getHeight(root->right)) +1);
}
bool isBalanced (node* root)
{
	if (root == NULL)
		return true;
	int lh = getHeight (root->left);
	int rh = getHeight (root->right);
	if (abs (lh - rh) <= 1 and isBalanced (root->left) and isBalanced (root->right))
		return true;
	return false;
}
int main()
{
	int n;
	node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);
	}
	if (isBalanced(root))
		cout << "Yes \n";
	else
		cout << "NO\n";


}
