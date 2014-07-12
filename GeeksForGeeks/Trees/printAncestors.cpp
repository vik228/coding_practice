#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
node* create (node* root, int data)
{
	root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}
void printAncestors (node* root, int key)
{
	stack <node*> s;
	s.push (root);
	while (!s.empty())
	{
		//cout << "hii\n";
		node* q = s.top();
		while (q->left != NULL)
		{
			q = q->left;
			s.push (q);
		}
		if (s.top()->data == key)
			break;
		if (s.top()->right == NULL)
		{
			q = s.top();
			s.pop();
			while (!s.empty() and q == s.top()->right)
			{
				//cout << "hii\n";
				q = s.top();
				s.pop();
			}
		}
		if (!s.empty())
			s.push (s.top()->right);
	}
	cout << key << ": "; 
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();

	}

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
	//scanf ("%d",&n);
	int val;
	node* root = NULL;
	root = create (root, 1);
	root->left = create (root->left,2);
	root->right = create (root->right, 3);
	root->left->left = create (root->left->left, 4);
	root->left->right = create (root->left->right, 5);
	root->right->left = create (root->right->left, 6);
	root->right->right = create (root->right->right, 7);
	root->right->right->left = create (root->right->right->left, 8);
	//inorder (root);
	int key;
	for (int i = 1; i <= 8; i++)
	{
		printAncestors (root, i);
	}

}

