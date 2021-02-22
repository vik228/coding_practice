#include <bits/stdc++.h>
using namespace std;
#define DEFAULT_SIZE 1000
template<typename T>
class Queue {
  private:
    int size;
    int f;
    T* queue;
  public:
    Queue();
    Queue(int s);
    void push(T ele);
    void pop();
    T front();
};

template<typename T>
Queue<T>::Queue() {
  queue = new T[DEFAULT_SIZE];
  size = 0;
  f = 0;
}

template<typename T>
Queue<T>::Queue(int s) {
  queue = new T[s];
  size = 0;
  f = 0;
}

template<typename T>
void Queue<T>::push(T ele) {
  queue[size++] = ele; 
}

template<typename T>
void Queue<T>::pop() {
  f++;
}

template<typename T>
T Queue<T>::front() {
  return queue[f];
}

int main() {
  Queue<int> queue;
  queue.push(1);
  cout << queue.front() << "\n";
  queue.push(2);
  queue.pop();
  cout << queue.front() << "\n";
}

