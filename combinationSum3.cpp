#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(int k, int sum, int st, vector<int>& temp) {
        if (temp.size() == k) {
            if (sum == 0) ans.push_back(temp);
            return;
        }
        if (sum < 0) return;

        for (int i = st; i <= 9; i++) {
            temp.push_back(i);
            helper(k, sum - i, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        helper(k, n, 1, temp);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(k, n);

    for (auto &v : res) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i + 1 < v.size()) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
