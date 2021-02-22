#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int minSubsetSumDiff(vector<int> v1, int sum1, int sum2, int idx) {
    if (idx >= v1.size()) {
        return abs(sum1 - sum2);
    }
    if (dp[idx][sum1] != -1) {
        return dp[idx][sum1];
    }
    int diff1 = minSubsetSumDiff(v1, sum1 + v1[idx], sum2, idx+1);
    int diff2 = minSubsetSumDiff(v1, sum1, sum2 + v1[idx], idx+1);
    dp[idx][sum1] = min(diff1, diff2);
    return min(diff1, diff2);
}

int minSubsetSumDiffDP(vector<int> v1, int sum, int totalSum) {
    vector<vector<bool>> dp1;
    dp1.resize(2, vector<bool>(sum + 1, false));
    dp1[0][0] = true;
    for (int i = 1; i <= sum; i++) {
        if (i == v1[i]) {
            dp1[0][i] = true;
        }
    }
    for (int i = 1; i < v1.size(); i++) {
        for (int j = 1; j <= sum; j++) {
            int row = (i-1)%2;
            if(dp1[row][j]) {
                dp1[i%2][j] = dp1[row][j]; 
            } else if (j >= v1[i]) {
                dp1[i%2][j] = dp1[row][j - v1[i]];
            }
        }
    }
    int sum1 = 0;
    int i = v1.size()%2;
    for (int j = sum; j >= 0; j--) {
        if (dp1[i][j]) {
            sum1 = j;
            break;
        }
    }
    return (abs(sum1 - (totalSum - sum1))); 
}
int main() {
    vector<int> v1 = {1, 2, 3, 9};
    int sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += v1[i];
    }
    cout << minSubsetSumDiffDP(v1, sum/2, sum) << "\n";
    return 0;
}