#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
bool isprime[1001];
vi primes;
void seive(int n) {
    fill(isprime, isprime + n + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isprime[i])
            primes.push_back(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive(200);
    for (auto p : primes)
        cout << p << " ";
    return 0;
}