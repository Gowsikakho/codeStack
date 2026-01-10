#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 🔹 Recursive function to generate all subsequences
void generateSubsequences(const string &s, string current, int index, vector<string> &result) {
    if (index == s.size()) {
        result.push_back(current); // add current subsequence
        return;
    }

    // Case 1: Exclude current character
    generateSubsequences(s, current, index + 1, result);

    // Case 2: Include current character
    generateSubsequences(s, current + s[index], index + 1, result);
}

void generateSubsequences(string s) {
    int n = s.length();

    for (int mask = 0; mask < (1 << n); mask++) {
        string subseq = "";

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq += s[i];
            }
        }

        cout << subseq << endl;
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> subsequences;
    generateSubsequences(s, "", 0, subsequences);

    // Optional: sort the subsequences alphabetically
    sort(subsequences.begin(), subsequences.end());

    cout << "\nAll Subsequences:\n";
    for (const auto &sub : subsequences) {
        if (sub.empty())
            cout << "'' (empty)\n";
        else
            cout << sub << "\n";
    }

    cout << "\nTotal subsequences: " << subsequences.size() << endl;

    return 0;
}
