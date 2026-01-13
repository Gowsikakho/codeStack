#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, string> mpp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void helper(string &digits, int index, string &temp, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mpp[digits[index]];
        for (char ch : letters) {
            temp.push_back(ch);          // choose
            helper(digits, index + 1, temp, ans);
            temp.pop_back();             // backtrack
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
