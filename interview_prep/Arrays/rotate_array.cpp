#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& v1, int s, int e) {
    while(s < e) {
        swap(v1[e], v1[s]);
        s++;
        e--;
    }
}
void rotate_array(vector<int>& arr, int n) {
    int len = arr.size();
    if (n < 0) {
        n += arr.size();
    } else {
        n = n % arr.size();
    }
    reverse(arr, 0, len-1);
    reverse(arr, 0, n-1);
    reverse(arr, n, len-1);
}