#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, string> mpp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void helper(string &digits, int ind, string &temp, vector<string> &ans) {
        if (ind == digits.size()) {
            ans.push_back(temp);
            return;
        }

        for (char ch : mpp[digits[ind]]) {
            temp.push_back(ch);              // choose
            helper(digits, ind + 1, temp, ans);
            temp.pop_back();                 // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        string temp;
        helper(digits, 0, temp, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "Letter combinations:\n";
    for (const string &s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
