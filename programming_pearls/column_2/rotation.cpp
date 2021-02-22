#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

void rotate_vector_juggling(vector<int> v1, int i, int n) {
  
  for (int k = 0; k < gcd(n, i); k++) {
    int temp = v1[k];
    int j = k + i;
    int t = k;
    while (true) {
      swap(v1[j], v1[t]);
      t = j;
      if ((j + i)%n == k) {
        v1[j] = temp;
        break;
      }
      j = (j + i)%n
    }
  }

}

int main() {
  vector<int> v1;
  int n, i;
  cin >> n >> i;
  for (int k = 0; k < n; k++) {
    int val;
    cin >> val;
    v1.push_back(val);
  }

}
