#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rev(i,a,b) for(int i=(a);i>=(b);--i)
#define sz(x) (int)(x).size()
#define lb(v,x) lower_bound(all(v),x)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define mat(N, M, val) vector<vector<int>>(N, vector<int>(M, val))

const int INF = 1e18;
const int MOD = 1e9 + 7;
bool isSort(vi& a,int n,int i){
    if(i==n-1)
        return true;
    return a[i]<=a[i+1] && isSort(a,n,i+1);
}
int linear(vi& a,int n,int i,int tar){
    if(i>n-1)
        return -1;
    if(a[i]==tar)
        return i;
    return linear(a,n,i+1,tar);
}
int binary(vi& a,int s,int e,int tar){
    if(s>e)
        return -1;
    int mid=s + (e - s) / 2;
    if(a[mid]==tar)
        return mid;
    if(a[mid]>tar)
        return binary(a,s,mid-1,tar);
    return binary(a,mid+1,e,tar);
    
}
int rotBinary(vi& a, int s, int e, int tar) {
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (a[mid] == tar)
        return mid;
    if (a[s] <= a[mid]) {
        if (tar >= a[s] && tar < a[mid])
            return rotBinary(a, s, mid - 1, tar);
        else
            return rotBinary(a, mid + 1, e, tar);
    }
    else {
        if (tar > a[mid] && tar <= a[e])
            return rotBinary(a, mid + 1, e, tar);
        else
            return rotBinary(a, s, mid - 1, tar);
    }
}

int main() {
    int n=9;
    vi a={3,6,7,9,22};
    int tar=9;
    cout<<rotBinary(a,0,n-1,9)<<endl;
}