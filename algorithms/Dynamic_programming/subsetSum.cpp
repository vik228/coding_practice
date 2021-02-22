#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

bool subsetSumRecursive(vector<int> &num, int sum, int idx) {
    if (idx >= num.size() or sum < 0) {
        return false;
    }
    if (sum == 0) {
        return true;
    }
    if (dp[idx][sum] != -1) {
        return dp[idx][sum];
    }
    bool include = false, exclude = false;
    if ((sum - num[idx]) >= 0) {
        include = subsetSumRecursive(num, sum - num[idx], idx + 1);
    }
    exclude = subsetSumRecursive(num, sum, idx + 1);
    dp[idx][sum] = (include or exclude);
    return dp[idx][sum];
}
bool subsetSumBottomUp(vector<int> &num, int sum) {
    dp.resize(2, vector<int>(sum + 1, 0));
    for (int i = 0; i < 2; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= sum; i++) {
        if (num[i] == sum) {
            dp[0][1] = 1;
        }
    }
    for (int i = 1; i < num.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            if (dp[(i-1)%2][j]) {
                dp[i%2][j] = dp[(i-1)%2][j];
            } else if (j >= num[i]){
                dp[i%2][j] = dp[(i-1)%2][j-num[i]];
            }
        }
    }
    return dp[(num.size()-1)%2][sum];
}
bool subSetSum(vector<int> &num) {
    int totalSum = 0;
    for (int i = 0; i < num.size(); i++) {
        totalSum += num[i];
    }
    if (totalSum % 2 != 0) {
        return false;
    }
    dp.resize(num.size() + 1, vector<int>(totalSum/2 + 1, -1));
    return subsetSumBottomUp(num, totalSum/2);
}

int main() {
    vector<int> num = {1, 2, 3, 4};
    cout << subSetSum(num) << "\n";
    return 0;
}