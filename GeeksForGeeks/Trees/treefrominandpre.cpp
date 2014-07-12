#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
string in, pre, post;
struct Node
{
	char data;
	Node *left, *right;
};
int pos = 0;
Node* makeTree (Node* root, int i, int j)
{
	if (i > j)
		return NULL;
	int found = in.find (pre[pos++]);
	if (i == j)
	{
		//cout << "Appending " << in[i] << " as" << root << "\n";
		root = new Node;
		root->data = in[i];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	//cout << "Appending " << pre[pos-1] << " as" << root << "\n";
	root = new Node;
	root->data = pre[pos-1];
	root->left = NULL;
	root->right = NULL;
	root->left = makeTree (root->left, i, found - 1);
	root->right = makeTree (root->right, found + 1, j);
	return root;
	

}
void postorder (Node* root)
{
	if (root != NULL)
	{
		postorder (root->left);
		postorder (root->right);
		cout << root->data << " ";
	}
}
int main()
{
	cin >> in;
	cin >> pre;
	Node* root = NULL;
	root = makeTree(root, 0, in.length()-1);
	postorder (root);
	//cout << root->data << "\n";

}
