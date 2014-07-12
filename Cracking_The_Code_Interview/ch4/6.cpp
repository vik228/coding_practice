#include <iostream>
#include <cstdio>
using namespace std;
struct Node 
{
	int data;
	Node *left, *right, *parent;
};
Node* create (Node* root, int val)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
	else if (val < root->data)
	{
		root->left = create (root->left, val);
		root->left->parent = root;
	}
	else
	{
		root->right = create (root->right, val);
		root->right->parent = root;
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
	//cout << "\n";
}
int goLeft (Node* root)
{
	if (root->left == NULL)
		return root->data;
	return (goLeft (root->left));
}
int getInorderSuccessor (Node* root)
{
	cout << root->data << "\n";
	if (root->right != NULL)
	{
		Node* p = root->right;
		return (goLeft (p));
	}
	else
	{
		Node* q = root;
		bool val = true;
		while (q->parent->left != q)
		{
			q = q->parent;
			if (q->parent == NULL)
			{
				val = false;
				break;
			}
		}
		if (val)
		{
			return q->parent->data;	
		}
		else
		{
			return 0;
		}
	}
}
int main ()
{
	Node *root = NULL;
	int a = 5;
	while (a--)
	{
		int val;
		scanf ("%d",&val);
		root = create (root, val);
	}
	inorder (root);
	cout << "\n";
	Node* p = root->right;
	cout << getInorderSuccessor (p) << "\n";
	//cout << p << " " << p->parent->left << "\n";
	return 0;
}
