#include <iostream>
#include <cstdio>
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
void deepestLeftLeafNode (node* root, bool isLeft, node **deepestLeafNode, int height, int* maxHeight)
{
	if (root == NULL)
		return;
	if (isLeft and *maxHeight < height and root->left != NULL and root->right != NULL) 
	{
		*deepestLeafNode = root;
		*maxHeight = height;
		return;
	}
	deepestLeftLeafNode (root->left, true, deepestLeafNode, height+1, maxHeight);
	deepestLeftLeafNode (root->right, false, deepestLeafNode, height+1, maxHeight);
	
	
}
int main()
{
	int n;
	cin >> n;
	node* root = NULL;
	int val;
	while (n--)
	{
		scanf ("%d",&val);
		root = makeTree (root, val);
	}
	int maxLevel = 0;
	node *ans = NULL;
	deepestLeftLeafNode (root, 0, &ans, 0, &maxLevel);
	cout << ans->data << "\n";
}
