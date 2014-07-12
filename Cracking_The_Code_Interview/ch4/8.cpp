#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
vector <int> in;
int idx;
Node* create (Node* root, int val)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > val)
	{
		root->left = create (root->left, val);
	}
	else
	{
		root->right = create (root->right, val);
	}
	return root;
}
void inorder (Node* root)
{
	if (root != NULL)
	{
		inorder (root->left);
		in.push_back (root->data);
		inorder (root->right);
	}
}
bool isSubTree(Node* root)
{
	if (root == NULL)
		return false;
	
}
int main()
{
	Node *root, *root1;
	int a = 11;
	while (a--)
	{
		int val;
		scanf ("%d",&val);
		root = create (root, val);
	}
	a = 5;
	while (a--)
	{
		int val;
		scanf ("%d",&val);
		root1 = create (root1, val);
	}
	inorder (root1);
	if (isSubTree (root))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;

}
