#include <iostream>
#include <cstdio>
#include <vector>
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
	else if (node->data < data)
	{
		node->right = create (node->right, data);
	}
	else
		node->left = create (node->left, data);
	return node;
}
void printRootToLeafPaths (Node* root, vector<int> v1)
{
	if (root == NULL)
		return;
	if (root->left == NULL and root->right == NULL)
	{
		for (int i = 0; i < v1.size(); i++)
			cout << v1[i]  << " ";
		cout << root->data << "\n";
		return;
	}
	v1.push_back (root->data);
	printRootToLeafPaths (root->left, v1);
	printRootToLeafPaths (root->right, v1);

}
int main ()
{
	int t;
	scanf ("%d",&t);
	int val;
	Node* root = NULL;
	while (t--)
	{
		scanf ("%d",&val);
		root = create (root, val);
		
	}
	vector <int> v1;
	printRootToLeafPaths (root, v1);
}
