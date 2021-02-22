#include <bits/stdc++.h>
using namespace std;

int find_least_common_number(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
  int i = 0, j = 0, k = 0;
  while(i < arr1.size() and j < arr2.size() and k < arr3.size()) {
    int max_ele = max(arr1[i], max(arr2[j], arr3[k]));
    if (arr1[i] == max_ele and arr2[j] == max_ele and arr3[k] == max_ele) {
      return max_ele;
    }
    if (arr1[i] != max_ele) {
      i++;
    }
    if (arr2[j] != max_ele) {
      j++;
    }
    if (arr3[k] != max_ele) {
      k++;
    }
  }
  return -1;
}