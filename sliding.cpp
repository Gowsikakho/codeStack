#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back

// General sliding window pattern
int slidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, ans = 0;
    unordered_map<int,int> freq;

    rep(r, 0, n) {
        freq[nums[r]]++;

        while(freq.size() > k) {
            freq[nums[l]]--;
            if(freq[nums[l]] == 0) freq.erase(nums[l]);
            l++;
        }

        ans = max(ans, r - l + 1);
    }
    return ans;
}
