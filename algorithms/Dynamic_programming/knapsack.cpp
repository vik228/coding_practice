#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int knapsackRecursive(vector<int> values, vector<int> weights, int capacity, int idx) {
    if (idx >= values.size() || capacity <= 0) {
        return 0;
    }
    int profitInclude = 0;
    if (weights[idx] <= capacity) {
        profitInclude = values[idx] + knapsackRecursive(values, weights, capacity - weights[idx], idx+1);
    }
    int profitExclude = knapsackRecursive(values, weights, capacity,idx+1);
    return max(profitInclude, profitExclude);
}

int knapsackRecursiveMemoised(vector<int> values, vector<int> weights, int capacity, int idx) {
    if (idx >= values.size() || capacity <= 0) {
        return 0;
    }
    int profitInclude = 0;
    if (weights[idx] <= capacity) {
        profitInclude = values[idx] + knapsackRecursive(values, weights, capacity - weights[idx], idx+1);
    }
    if (dp[idx][capacity] != -1) {
        return dp[idx][capacity];
    }
    int profitExclude = knapsackRecursive(values, weights, capacity,idx+1);
    dp[idx][capacity] = max(profitInclude, profitExclude);
    return max(profitInclude, profitExclude);
}

int knapsackRecursiveBottomUp(vector<int> values, vector<int> weights, int capacity) {
    // dp[i][c] = max knapsack profit for capacity c using first i items
    for (int i = 0; i < 2; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= capacity; i++) {
        if (weights[0] <= i) {
            dp[0][i] = values[0];
        }
    }
    for (int i = 1; i < values.size(); i++) {
      for (int c = 1; c <= capacity; c++) {
        int profit1 = 0, profit2 = 0;
        int row = (i-1)%2;
        if (weights[i] <= c) {
          profit1 = values[i] + dp[row][c - weights[i]];
        }
        profit2 = dp[row][c];
        dp[i%2][c] = max(profit1, profit2);
      }
    }
    return dp[(values.size() - 1)%2][capacity];
}

int main() {
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int capacity = 7;
    dp.resize(2, vector<int>(capacity + 1, -1));
    cout << knapsackRecursiveBottomUp(profits, weights, capacity) << "\n";
    return 0;
}