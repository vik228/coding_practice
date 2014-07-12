#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node
{
	int val;
	node *left, *right;
};
vector <int> v1;
node* newNode (int data)
{
	node* n1 = new node;
	n1->val = data;
	n1->left = NULL;
	n1->right = NULL;
	return n1;
}
int sumRootToLeafPath (node* root, int number)
{
	if (root == NULL)
		return 0;
	number = 10*number + root->val;
	if (root->left == NULL and root->right == NULL)
	{
		return number;

	}
	return (sumRootToLeafPath (root->left, number) + sumRootToLeafPath (root->right, number));

}
int main()
{
	node* root = NULL;
	root = 	newNode (6);
	root->left        = newNode(3);
	root->right       = newNode(5);
	root->right->right= newNode(7);
	root->left->left  = newNode(2);
	root->left->right = newNode(5);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	cout << sumRootToLeafPath (root, 0) << "\n";
}
