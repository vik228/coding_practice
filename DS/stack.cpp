#include <bits/stdc++.h>
using namespace std;
#define DEFAULT_SIZE 1000
template <typename T>
class Stack {
  private:
    int size;
    T* stk;
  public:
    Stack();
    Stack(int size);
    void push(T ele);
    void pop();
    T top();
    ~Stack();
};

template <typename T>
Stack<T>::Stack() {
  stk = new T[DEFAULT_SIZE];
  size = 0;
}

template <typename T>
Stack<T>::Stack(int capacity) {
  stk = new T[capacity];
  size = 0;
}

template <typename T>
void Stack<T>::push(T ele) {
  stk[size++] = ele;
}

template <typename T>
void Stack<T>::pop() {
  size--;
}

template <typename T>
T Stack<T>::top() {
  return stk[size-1];
}

template <typename T>
Stack<T>::~Stack() {
  delete [] stk;
}

int main() {
  Stack<int> s(5);
  s.push(2);
  s.push(3);
  cout << s.top() << "\n";
  s.pop();
  cout << s.top() << "\n";
}


