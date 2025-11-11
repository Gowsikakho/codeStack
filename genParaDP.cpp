#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int l, int r, int n, string &temp, vector<string> &ans) {
        if (l + r == 2 * n) {
            ans.push_back(temp);
            return;
        }
        if (l < n) {
            temp.push_back('(');
            solve(l + 1, r, n, temp, ans);
            temp.pop_back();
        }
        if (r < l) {
            temp.push_back(')');
            solve(l, r + 1, n, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, 0, n, temp, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "\nAll valid combinations of parentheses are:\n";
    for (auto &s : result) {
        cout << s << "\n";
    }

    return 0;
}
