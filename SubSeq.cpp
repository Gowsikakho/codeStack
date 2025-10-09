#include <bits/stdc++.h>
using namespace std;

// 🔹 Recursive function to generate all subsequences
void generateSubsequences(string s, string current, int index, vector<string> &result) {
    // Base case: when we reach the end of the string
    if (index == s.size()) {
        result.push_back(current);
        return;
    }

    // Case 1: Exclude current character
    generateSubsequences(s, current, index + 1, result);

    // Case 2: Include current character
    generateSubsequences(s, current + s[index], index + 1, result);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> subsequences;
    generateSubsequences(s, "", 0, subsequences);

    cout << "\nAll Subsequences:\n";
    for (auto &sub : subsequences)
        cout << (sub.empty() ? "'' (empty)" : sub) << "\n";

    return 0;
}
