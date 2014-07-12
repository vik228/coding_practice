#include <iostream>
#include <cstdio>
#include  <queue>
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
int diameter (node* root, int* height)
{
	cout << "hii\n";
	int lh = 0, rh = 0;
	if (root == NULL)
	{
		*height = 0;
		return 0;
	}
	int ldiameter = diameter (root->left, &lh);
	int rdiameter = diameter (root->right, &rh);
	*height = max (lh, rh) + 1;
	return max (lh+rh+1, max (ldiameter, rdiameter));

}
int main()
{
	int n;
	node* root = NULL;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf ("%d",&val);
		root = makeTree (root, val);
	}
	int height = 0;
	cout << diameter (root, &height) << "\n";


}
