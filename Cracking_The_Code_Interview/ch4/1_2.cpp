#include <iostream>
#include <cstdio>
#include <cstdlib>
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
}
int checkHeight (Node* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = checkHeight (root->left);
	if (leftHeight == -1)
		return -1;
	int rightHeight = checkHeight (root->right);
	if (rightHeight == -1)
		return -1;
	diff = abs (rightHeight - leftHeight);
	if (diff > 1)
		return -1;
	else
		return max ((checkHeight (root->left), checkHeight (root->right)) + 1);
}
int main()
{
	
}
