#include <bits/stdc++.h>
using namespace std;

/*---------------- RECURSION ----------------*/
bool rec(int i, int target, vector<int>& a){
    if(target==0) return true;
    if(i==0) return a[0]==target;

    bool nottake = rec(i-1,target,a);
    bool take = false;

    if(a[i] <= target)
        take = rec(i-1,target-a[i],a);

    return take || nottake;
}

/*---------------- MEMOIZATION ----------------*/
bool memo(int i,int target,vector<int>& a,vector<vector<int>>& dp){
    if(target==0) return true;
    if(i==0) return a[0]==target;

    if(dp[i][target]!=-1)
        return dp[i][target];

    bool nottake = memo(i-1,target,a,dp);
    bool take = false;

    if(a[i] <= target)
        take = memo(i-1,target-a[i],a,dp);

    return dp[i][target] = take || nottake;
}

/*---------------- TABULATION ----------------*/
bool tab(vector<int>& a,int target){
    int n = a.size();

    vector<vector<bool>> dp(n,vector<bool>(target+1,false));

    for(int i=0;i<n;i++)
        dp[i][0] = true;

    if(a[0] <= target)
        dp[0][a[0]] = true;

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){

            bool nottake = dp[i-1][t];
            bool take = false;

            if(a[i] <= t)
                take = dp[i-1][t-a[i]];

            dp[i][t] = take || nottake;
        }
    }

    return dp[n-1][target];
}

/*---------------- SPACE OPTIMIZATION ----------------*/
bool spaceOpt(vector<int>& a,int target){
    int n = a.size();

    vector<bool> prev(target+1,false);
    prev[0] = true;

    if(a[0] <= target)
        prev[a[0]] = true;

    for(int i=1;i<n;i++){

        vector<bool> cur(target+1,false);
        cur[0] = true;

        for(int t=1;t<=target;t++){

            bool nottake = prev[t];
            bool take = false;

            if(a[i] <= t)
                take = prev[t-a[i]];

            cur[t] = take || nottake;
        }

        prev = cur;
    }

    return prev[target];
}

/*---------------- MAIN ----------------*/
int main(){

    vector<int> arr = {2,3,7,8,10};
    int target = 11;
    int n = arr.size();

    cout<<"Recursion: "<<rec(n-1,target,arr)<<endl;

    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<"Memoization: "<<memo(n-1,target,arr,dp)<<endl;

    cout<<"Tabulation: "<<tab(arr,target)<<endl;

    cout<<"Space Optimized: "<<spaceOpt(arr,target)<<endl;

    return 0;
}