#include <bits/stdc++.h>
using namespace std;

// 🔹 Function 1: Generate all substrings
vector<string> getAllSubstrings(const string &s) {
    vector<string> subs;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            subs.push_back(s.substr(i, j - i + 1));
        }
    }
    return subs;
}

// 🔹 Function 2: Check if a string is palindrome
bool isPalindrome(const string &str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++, r--;
    }
    return true;
}

// 🔹 Function 3: Print all palindromic substrings
void printPalindromicSubstrings(const string &s) {
    vector<string> subs = getAllSubstrings(s);
    cout << "Palindromic Substrings:\n";
    for (auto &sub : subs) {
        if (isPalindrome(sub))
            cout << sub << "\n";
    }
}

// 🔹 Main Function
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    printPalindromicSubstrings(s);
    return 0;
}
