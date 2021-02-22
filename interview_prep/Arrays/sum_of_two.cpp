#include <bits/stdc++.h>
using namespace std;

bool find_sum_of_two(vector<int>& A, int val) {
  unordered_map<int, bool> umap;
  for (int i = 0; i < A.size(); i++) {
    int diff = val - A[i];
    if (umap.find(diff) != umap.end()) {
      return true;
    }
    umap[A[i]] = true;
  }
  return false;
}