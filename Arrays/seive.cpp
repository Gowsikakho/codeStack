#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
vector<bool> isprime; // dynamic size
vi primes;
int maxComputed = 1;  // keeps track of how far sieve has been compute
// Incremental sieve function
void seive(int n) {
    if (n <= maxComputed) return; // already computed up to this value
    int oldSize = maxComputed + 1;
    isprime.resize(n + 1, true);
    // initialize new elements if needed
    for (int i = oldSize; i <= n; i++) 
        isprime[i] = true;

    // mark 0 and 1 if not already
    if (maxComputed < 1) isprime[0] = isprime[1] = false;

    // sieve from 2 up to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            int start = max(i*i, ((maxComputed+1 + i - 1)/i)*i); // start from next unmarked
            for (int j = start; j <= n; j += i)
                isprime[j] = false;
        }
    }

    // append new primes
    for (int i = maxComputed + 1; i <= n; i++) {
        if (isprime[i]) primes.push_back(i);
    }

    maxComputed = n; // update max computed
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive(200);
    for (auto p : primes)
        cout << p << " ";
    return 0;
}