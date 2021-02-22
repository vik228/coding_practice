#include <bits/stdc++.h>
using namespace std;

int binary_search_rotated(vector<int>& arr, int key) {
  int lo = 0;
  int hi = arr.size() - 1;
  while(lo <= hi) {
    int mid = lo + (hi - lo)/2;
    if (arr[mid] == key) {
      return mid;
    }
    if (arr[lo] <= arr[mid]) {
      if (key >= arr[lo] and key < arr[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else {
      if (key > arr[mid] and key <= arr[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  return -1;
}