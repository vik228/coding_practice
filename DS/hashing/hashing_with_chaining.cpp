#include <iostream>
#include <list>
using namespace std;

class Hash {
  int bucket;
  list<int> *table;

  public:
    Hash(int V);

    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x) {
      return (x % bucket);
    }
    void displayHash();
};

Hash::Hash(int b) {
  this->bucket = b;
  this->table = new list<int>[b];
}

void Hash::insertItem(int x) {
  int index = hashFunction(x);
  table[index].push_back(x);
}

void Hash::deleteItem(int key) {
  int index = hashFunction(key);
  list <int> :: iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
  if (i != table[index].end()) {
    table[index].erase(i);
  }
}

void Hash::displayHash() {
  for (int i = 0; i < bucket; i++) {
    cout << i;
    for (auto x: table[i]) {
      cout << "->" << x;
    }
    cout << endl;
  }
}

int main() {
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
  Hash h(7);
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);

  h.deleteItem(12);
  h.displayHash();

  return 0;
}
