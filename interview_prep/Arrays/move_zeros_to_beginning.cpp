#include <bits/stdc++.h>
using namespace std;

void move_zeros_to_left(int A[], int n) {
  //TODO: Write - Your - Code
  int i = n-1;
  int j = n-1;
  while(i >= 0) {
    if (A[j] == 0 and A[i] == 0) {
      i--;
    } else if (A[j] == 0 and A[i] != 0) {
      swap(A[j--], A[i--]);
    } else if (A[j] != 0 and A[i] != 0) {
      i--;
      j--;
    }
  }
}