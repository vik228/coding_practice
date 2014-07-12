#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
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
		cout << root->data << " ";
		inorder (root->right);
	}
}
bool isOnLeft (Node* root, Node* p)
{
	if (root == NULL)
		return false;
	else if (p == root)
		return true;
	else
		return (isOnLeft(root->left, p) or isOnLeft (root->right, p));
}
Node* getLCS (Node* root, Node* p, Node* q)
{
	if (root == NULL)
		return NULL;
	if (root == p or root == q)
		return root;
	bool a1 = isOnLeft (root, p);
	bool a2 = isOnLeft (root, q);
	if (a1 != a2)
		return root;
	else
	{
		Node* n = a1 ? root->left : root->right;
	}
}
void LCS (Node *root, Node *p, Node* q)
{
	if (p != NULL and q != NULL)
	{
		Node *lcs = getLCS (root, p, q);
		cout << lcs->data << "\n";
	}
}
int main()
{

	int a = 11;
	Node* root = NULL;
	while (a--)
	{
		int val;
		scanf ("%d",&val);
		root = create (root, val);
	}
	Node *p, *q;
	p = q = root;
	//cout << root->data << "\n";
	while (p->left != NULL)
	{
		p = p->left;
	}
	q = root->left;
	while (q->right != NULL)
		q = q->right;
	//cout << root->data << "\n";
	LCS (root, p, q);
	return 0;

}

