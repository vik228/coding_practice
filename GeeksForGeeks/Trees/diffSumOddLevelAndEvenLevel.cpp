#include <cstdio>
#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left, *right;
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
	else if (root->data < data)
		root->right = makeTree (root->right, data);
	else if (root->data > data)
		root->left = makeTree (root->left, data);
	return root;
}
void findSum (node* root, int *sumOdd, int *sumEven, int level)
{
	if (root == NULL)
		return;
	if (level % 2 == 0)
	{
		*sumEven += root->data;
	}
	else if (level % 2 == 1)
	{
		*sumOdd += root->data;
	}
	findSum (root->left, sumOdd, sumEven, level+1);
	findSum (root->right, sumOdd, sumEven, level+1);
}
int main()
{
	int n;
	scanf ("%d",&n);
	node* root = NULL;
	while (n--)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);

	}
	int sumOdd = 0;
	int sumEven = 0;
	findSum (root, &sumOdd, &sumEven, 0);
	cout << (sumOdd-sumEven) << "\n";
}
