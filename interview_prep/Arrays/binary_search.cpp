#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> v1, int target) {
    int lo = 0;
    int hi = v1.size();

    while(lo < hi) {
        int mid = lo + (hi - lo)/2;
        if (v1[mid] == target) {
            return true;
        }
        if (v1[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return false;
}