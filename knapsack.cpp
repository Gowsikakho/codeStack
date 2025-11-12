#include <bits/stdc++.h>
using namespace std;

int knapsackMemo(int index, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (index == 0) {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[index][W] != -1)
        return dp[index][W];

    int notTake = knapsackMemo(index - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[index] <= W)
        take = val[index] + knapsackMemo(index - 1, W - wt[index], wt, val, dp);

    return dp[index][W] = max(take, notTake);
}

int main() {
    int n = 4, W = 7;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Maximum value (Memoization): " 
         << knapsackMemo(n - 1, W, wt, val, dp) << endl;
    return 0;
}
