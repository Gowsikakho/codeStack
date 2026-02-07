#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                cur[j] = pre[j] + cur[j - 1];
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    Solution sol;
    int result = sol.uniquePaths(m, n);

    cout << "\nNumber of unique paths from top-left to bottom-right: " << result << "\n";

    return 0;
}
