#include <iostream>
#include "Node.h"
using namespace std;
class List
{
	private:
		int size;
		Node* headNode;
		Node* currentNode;
		Node* lastCurrentNode;
	public:
		List ()
		{
			headNode = new Node;
			headNode->setNext (NULL);
			currentNode = NULL;
			lastCurrentNode = NULL;
			size = 0;
		}
		void add (int obj)
		{
			Node* newNode = new Node;
			newNode->set (obj);
			if (currentNode != NULL)
			{
				newNode->setNext (currentNode->getNext());
				currentNode->setNext (newNode);
				lastCurrentNode = currentNode;
				currentNode = newNode;
			}
			else
			{
				newNode->setNext(NULL);
				headNode->setNext(newNode);
				lastCurrentNode = headNode;
				currentNode  = newNode;
			}
			size++;
		}
		int get()
		{
			if (currentNode != NULL)
				return currentNode->get();
		}
		bool next()
		{
			if (currentNode == NULL)
				return false;
			lastCurrentNode = currentNode;
			currentNode = currentNode->getNext();
			return true;
		}
		void start ()
		{
			lastCurrentNode = headNode;
			currentNode = headNode;
		}
		void remove ()
		{
			if (currentNode != NULL and currentNode != headNode)
			{
				lastCurrentNode->setNext (currentNode->getNext());
				delete currentNode;
				currentNode = lastCurrentNode->getNext();
				size--;
			}
		}
		int length ()
		{
			return size;
		}
		void incr_size ()
		{
			size++;
		}
		Node* getHead ()
		{
			return headNode->getNext();
		}
		bool checkNext  ()
		{
			return (currentNode->getNext() != NULL);
		}
		void setLastNext (int pos)
		{
			Node* head = headNode;
			for (int i = 0; i < pos; i++)
			{
				head = head->getNext();
			}
			//cout << head->get() << "\n";
			currentNode->setNext(head);
		}
		Node* getCurrentNode ()
		{
			return currentNode;
		}
		friend void traverse(List list);
		friend List addNodes(int data, int pos, List list);
};
void traverse (List list)
{
	Node* savedCurrentNode = list.currentNode;
	list.currentNode = list.headNode;
	int val = list.length();
	for (int i = 1; (list.next() and val > 0); i++)
	{
		cout << list.get() << " ";
		val--;
		
	}
	list.currentNode = savedCurrentNode;
	cout << "\n";
}
List addNodes (int data, int pos, List list)
{
	Node* savedCurrentNode = list.currentNode;
	list.currentNode = list.headNode;
	for (int i = 0; i < pos; i++)
		list.next();
	Node* n1 = new Node;
	n1->set (data);
	n1->setNext (list.currentNode->getNext()); 
	list.currentNode->setNext (n1);
	list.currentNode = savedCurrentNode;
}

