#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
Node* create (Node* node, int data)
{
	//cout << "hii\n";
	if (node == NULL)
	{
		node = new Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (node->data < data)
	{
		node->right = create (node->right, data);
	}
	else
		node->left = create (node->left, data);
	return node;
}
void PrintSpiralForm (Node* root)
{
	if (root == NULL)
		return;
	stack <Node*> s1, s2;
	s2.push (root);
	bool val = true;
	while (!s1.empty() or !s2.empty())
	{
		cout << "hii\n";
		while (!s2.empty())
		{
			Node* n1 = s2.top();
			cout << n1->data << " ";
			s2.pop();
			if (n1->left)
				s1.push(n1->left);
			if (n1->right)
				s1.push (n1->right);
		}
		while (!s1.empty())
		{
			Node* n2 = s1.top();
			cout << n2->data << " ";
			s1.pop();
			if (n2->right)
				s2.push (n2->right);
			if (n2->right)
				s2.push (n2->left);
		}
	}
}
int main()
{
	int n;
	scanf ("%d",&n);
	int val;
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&val);
		root = create (root, val);

	}
	PrintSpiralForm (root);

}
