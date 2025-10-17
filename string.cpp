#include <bits/stdc++.h>
using namespace std;

// ========================
// String Utility Functions
// ========================

// 1️⃣ Reverse a string
string reverseString(const string &s) {
    string res = s;
    reverse(res.begin(), res.end());
    return res;
}

// 2️⃣ Check if string is palindrome
bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

// 3️⃣ Convert to uppercase / lowercase
string toUpperCase(string s) {
    for (char &c : s) c = toupper(c);
    return s;
}
string toLowerCase(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

// 4️⃣ Character frequency
map<char, int> charFrequency(const string &s) {
    map<char, int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// 5️⃣ Remove duplicates from string
string removeDuplicates(const string &s) {
    string res;
    set<char> seen;
    for (char c : s) {
        if (!seen.count(c)) {
            res.push_back(c);
            seen.insert(c);
        }
    }
    return res;
}

// 6️⃣ Check if string contains only digits
bool isNumber(const string &s) {
    if (s.empty()) return false;
    for (char c : s) if (!isdigit(c)) return false;
    return true;
}

// 7️⃣ Split string by delimiter
vector<string> splitString(const string &s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delim)) tokens.push_back(token);
    return tokens;
}

// 8️⃣ String <-> Integer conversions
int stringToInt(const string &s) {
    return stoi(s);
}
string intToString(int x) {
    return to_string(x);
}

// 9️⃣ Check if substring exists
bool containsSubstring(const string &s, const string &sub) {
    return s.find(sub) != string::npos;
}

// 🔟 Trim spaces
string ltrim(const string &s) {
    size_t start = 0;
    while (start < s.size() && isspace(s[start])) start++;
    return s.substr(start);
}
string rtrim(const string &s) {
    int end = s.size() - 1;
    while (end >= 0 && isspace(s[end])) end--;
    return s.substr(0, end + 1);
}
string trim(const string &s) {
    return ltrim(rtrim(s));
}

// ========================
// Main function to test
// ========================
int main() {
    string s = "  hello world  ";
    cout << "Original: [" << s << "]\n";
    cout << "Trimmed: [" << trim(s) << "]\n";
    cout << "Uppercase: " << toUpperCase(s) << "\n";
    cout << "Lowercase: " << toLowerCase(s) << "\n";
    cout << "Reversed: " << reverseString(s) << "\n";
    cout << "Is palindrome? " << isPalindrome("level") << "\n";
    
    string dup = "aabbcc";
    cout << "Remove duplicates: " << removeDuplicates(dup) << "\n";

    string num = "12345";
    cout << "Is number? " << isNumber(num) << "\n";

    string text = "apple,banana,orange";
    auto parts = splitString(text, ',');
    cout << "Split string: ";
    for (auto &p : parts) cout << p << " ";
    cout << "\n";

    cout << "String to int: " << stringToInt("456") + 1 << "\n";
    cout << "Int to string: " << intToString(789) << "\n";

    cout << "Contains 'world'? " << containsSubstring(s, "world") << "\n";

    auto freq = charFrequency("abbccc");
    cout << "Character frequencies: ";
    for (const auto &p : freq) cout << p.first << ":" << p.second << " ";
    cout << "\n";

    return 0;
}
