#include <bits/stdc++.h>
using namespace std;

void permute(string &s, vector<bool> &used, string &curr) {
    // Base case
    if (curr.length() == s.length()) {
        cout << curr << endl;
        return;
    }

    // Try every character
    for (int i = 0; i < s.length(); i++) {
        if (used[i]) continue;

        used[i] = true;               // choose
        curr.push_back(s[i]);         // explore
        permute(s, used, curr);
        curr.pop_back();              // un-choose
        used[i] = false;
    }
}

void permute(string &s, int index) {
    // Base case
    if (index == s.length()) {
        cout << s << endl;
        return;
    }

    // Recursive case
    for (int i = index; i < s.length(); i++) {
        swap(s[index], s[i]);        // choose
        permute(s, index + 1);       // explore
        swap(s[index], s[i]);        // un-choose (backtrack)
    }
}

int main() {
    string s = "ABC";
    vector<bool> used(s.length(), false);
    string curr = "";

    permute(s, used, curr);
    return 0;
}
