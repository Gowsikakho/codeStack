#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n <= 1) {
            return dp[n];
        }
        if (dp[n] == -1)
            dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }

    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.countWays(n) << endl;

    return 0;
}
