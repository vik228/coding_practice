#include <bits/stdc++.h>
using namespace std;

// Index of first element greater than or equal to the target value.

int lower_bound(vector<int>& v1, int target) {
    int lo = 0;
    int hi = v1.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (target <= mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

// Index of the first element greater than the target value;

int upper_bound(vector<int>& v1, int target) {
    int lo = 0;
    int hi = v1.size() - 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (target >= v1[mid]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int searchInSortedAndRotated(vector<int>& v1, int target) {
    int lo = 0;
    int hi = v1.size() - 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (v1[mid] == target) {
            return mid;
        }
        if (v1[mid] >= v1[lo]) {
            if (target >= v1[lo] and target < v1[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > v1[mid] and target <= v1[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int longestSubArrayWithAtMostSumK(vector<int>& v1, int k) {
    int i = 0;
    int j;
    int sum = 0;
    int len = 0;
    for (j = 0; j < v1.size(); j++) {
        sum += v1[j];
        while (sum > k) {
            sum -= v1[i++];
        }
        len = max(len, j - i + 1);
    }
    return len;
}