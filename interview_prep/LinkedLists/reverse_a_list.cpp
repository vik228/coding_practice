#include <bits/stdc++.h>
using namespace std;
struct LinkedListNode
{
  int data;
  LinkedListNode *next;
  LinkedListNode *arbitrary_pointer;
  LinkedListNode(int d)
  {
    data = d;
    next = nullptr;
    arbitrary_pointer = nullptr;
  }
};

LinkedListNode* reverse(LinkedListNode* head) {
  //TODO: Write - Your - Code
  LinkedListNode* prev = NULL;
  LinkedListNode* next = NULL;
  LinkedListNode* curr = head;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}