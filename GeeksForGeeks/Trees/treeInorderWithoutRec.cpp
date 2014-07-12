#include <iostream>
#include <cstdio>
#include  <queue>
#include <stack>
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
void inorderWithoutRec (node *root)
{
	stack <node*> s;
	s.push (root);
	while (!s.empty())
	{
		node* q = s.top();
		while (q->left != NULL)
		{
			q = q->left;
			cout << "Pusing " << q->data << "\n";
			s.push (q);
		}
		cout << "q " <<  (q->data) << " ";
		//cout << "q->right " << q->right->data << "\n";
		if (!q->right)
		{
			cout << "popping " << s.top()->data << "\n";
			s.pop();
			//cout << q->data << "\n";
			while (!s.empty() and (s.top()->right) == q)
			{
				cout << "in" <<  s.top()->data << " " << "\n";
				q = s.top();
				s.pop();
			}
		}
		if (s.top()->right != NULL)
		{
			cout << "pushing " << (s.top()->right->data) << "\n";
			s.push (s.top()->right);
		}
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
	node* root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);
	}
	inorder (root);
	cout << "inorder without rec " << "\n";
	inorderWithoutRec (root);


}
