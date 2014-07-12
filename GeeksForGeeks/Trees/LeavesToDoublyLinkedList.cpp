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
void leafToDoublyLinkedList (node* root, node** head)
{
	if (root->left == NULL and root->right == NULL)
	{
		if (*head == NULL)
		{
			*head = root;
		}
		else
		{
			(*head)->right = root;
			root->left = *head;
			*head = root;
		}
		return;
	}
	leafToDoublyLinkedList (root->left, head);
	leafToDoublyLinkedList (root->right, head);
}
int main()
{
	int n;
	scanf ("%d",&n);
	int val;
	node* root = NULL;
	while (n--)
	{
		scanf ("%d",&val);
		root = makeTree (root, val);

	}
	node *head = NULL;
	leafToDoublyLinkedList (root, &head);
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->left;
	}
	return 0;
}
