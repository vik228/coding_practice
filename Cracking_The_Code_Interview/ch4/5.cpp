#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
struct Node 
{
	int data;
	Node *left, *right;
};
int val = INT_MIN;
Node* createBT (Node* root, char node, int data)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > data)
	{
		root->left = createBT (root->left, node, data);
	}
	else
	{
		root->right == createBT (root->right, node, data);
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
bool checkBST (Node* root)
{
	if (root == NULL)
		return true;
	bool a1 = checkBST (root->left);
	if (root->data >= val)
		val = root->data;
	else if (root->data < val)
		return false;
	bool a2 = checkBST (root->right);
	return (a1 and a2);

}
int main ()
{
	Node* root = NULL;
	int a = 5;
	while (a--)
	{
		int val;
		scanf ("%d",&val);
		root = createBT (root,'r',val);
	}
	inorder (root);
	if (checkBST (root))
		cout << "YES\n ";
	cout << "\n";

}
