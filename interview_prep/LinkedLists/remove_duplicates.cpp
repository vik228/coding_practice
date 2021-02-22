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

LinkedListNode* remove_duplicates(LinkedListNode* head){
  unordered_set<int> uset;
  LinkedListNode* curr = head;
  LinkedListNode* prev = NULL;
  while (curr != NULL) {
    if (uset.find(curr->data) != uset.end()) {
      prev->next = curr->next;
      LinkedListNode* temp = curr->next;
      delete(temp);
      curr = prev->next;
    } else {
      uset.insert(curr->data);
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}