#include <bits/stdc++.h>
using namespace std;
/*
    input [1,2,3,4]
    output [24,12,8,6]

    [24,12,4,1] -- suffix


    [1,2,3,4]
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> suffix(n, 0);
    suffix[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = nums[i+1]*suffix[i+1];
    }
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
        suffix[i] = prefix*suffix[i];
        prefix = prefix*nums[i];
    }
    return suffix;
}

int main() {
    vector<int> v1 = {1,2,3,4};
    vector<int> ans = productExceptSelf(v1);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}