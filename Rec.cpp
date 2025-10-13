#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------
  1️⃣ Factorial Function
------------------------------------------------*/
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

/*------------------------------------------------
  2️⃣ Fibonacci Function
------------------------------------------------*/
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

/*------------------------------------------------
  3️⃣ Greatest Common Divisor (Euclid’s Algorithm)
------------------------------------------------*/
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/*------------------------------------------------
  4️⃣ Power Function (a^b)
------------------------------------------------*/
int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

/*------------------------------------------------
  5️⃣ Print All Subsequences of a String
------------------------------------------------*/
void subsequence(string s, string curr = "", int index = 0) {
    if (index == s.length()) {
        cout << curr << endl;
        return;
    }
    // Include current character
    subsequence(s, curr + s[index], index + 1);
    // Exclude current character
    subsequence(s, curr, index + 1);
}

/*------------------------------------------------
  🔹 MAIN FUNCTION
------------------------------------------------*/
int main() {
    cout << "---- Recursive Functions Demo ----\n\n";

    // Factorial
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n) << "\n";

    // Fibonacci
    int f = 6;
    cout << "Fibonacci(" << f << ") = " << fib(f) << "\n";

    // GCD
    int a = 48, b = 18;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << "\n";

    // Power
    int base = 2, exp = 5;
    cout << base << "^" << exp << " = " << power(base, exp) << "\n";

    // Subsequences
    string str = "abc";
    cout << "\nSubsequences of \"" << str << "\":\n";
    subsequence(str);

    return 0;
}
