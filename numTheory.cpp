#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<vector<bool>>
#define rep(i,a,b) for(int i=a;i<b;i++)

const ll MOD = 1e9+7;

// ---------- GCD & LCM ----------
ll gcd(ll a, ll b) {
    return b==0 ? a : gcd(b,a%b);
}

ll lcm(ll a, ll b) {
    return (a/gcd(a,b))*b;
}

// ---------- Modular Exponentiation ----------
ll modpow(ll a,ll b,ll m=MOD){
    ll res=1; a%=m;
    while(b){
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

// ---------- Modular Inverse (Fermat’s theorem) ----------
ll modinv(ll a,ll m=MOD){
    return modpow(a,m-2,m);
}

// ---------- Factorials & nCr ----------
const int MAXN=1e6;
ll fact[MAXN+1],invFact[MAXN+1];

void initFactorials(int n=MAXN){
    fact[0]=1;
    rep(i,1,n+1) fact[i]=(fact[i-1]*i)%MOD;
    invFact[n]=modinv(fact[n]);
    for(int i=n;i>0;i--) invFact[i-1]=(invFact[i]*i)%MOD;
}

ll nCr(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

// ---------- Divisors ----------
vi divisors(int n){
    vi d;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i!=n/i) d.push_back(n/i);
        }
    }
    return d;
}

// ---------- Prime Check ----------
bool isPrime(ll n){
    if(n<2) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0) return false;
    }
    return true;
}

// ---------- Prime Factorization (trial division) ----------
vi factorize(int n){
    vi f;
    for(int p=2;p*p<=n;p++){
        while(n%p==0){
            f.push_back(p);
            n/=p;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}

// ---------- Fibonacci (fast doubling) ----------
pair<ll,ll> fib(ll n){
    if(n==0) return {0,1};
    auto p=fib(n>>1);
    ll a=p.first, b=p.second;
    ll c=(a*((2*b%MOD - a + MOD)%MOD))%MOD;
    ll d=(a*a%MOD + b*b%MOD)%MOD;
    if(n&1) return {d,(c+d)%MOD};
    else return {c,d};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initFactorials(); // Precompute factorials for nCr

    // --- Demo usage ---
    cout<<"gcd(48,18) = "<<gcd(48,18)<<"\n";
    cout<<"lcm(12,15) = "<<lcm(12,15)<<"\n";
    cout<<"nCr(10,3) = "<<nCr(10,3)<<"\n";

    vi d=divisors(36);
    cout<<"Divisors of 36: ";
    for(int x:d) cout<<x<<" ";
    cout<<"\n";

    vi f=factorize(84);
    cout<<"Prime factors of 84: ";
    for(int x:f) cout<<x<<" ";
    cout<<"\n";

    cout<<"isPrime(97) = "<<(isPrime(97)?"YES":"NO")<<"\n";

    auto fb=fib(10);
    cout<<"Fib(10) = "<<fb.first<<"\n";

    return 0;
}
