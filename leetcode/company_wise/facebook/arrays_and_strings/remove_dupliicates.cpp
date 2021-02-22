#include <bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> &nums) {
    int j = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && nums[i] == nums[i + 1]) {
            continue;
        }
        nums[j++] = nums[i];
    }
    return j;
}

int main() {
    int n;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v1.push_back(val);
    }
    cout << remove_duplicates(v1);
}