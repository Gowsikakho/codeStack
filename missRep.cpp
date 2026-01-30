#include <bits/stdc++.h>
using namespace std;

pair<int,int> findMissingRepeating(vector<int>& arr) {
    int n = arr.size();
    int repeat = -1, missing = -1;

    // Step 1: Find repeated number
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        if (arr[val - 1] < 0) {
            repeat = val;
        } else {
            arr[val - 1] = -arr[val - 1];
        }
    }

    // Step 2: Find missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {missing, repeat};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    auto ans = findMissingRepeating(arr);
    cout << "Missing: " << ans.first << "\n";
    cout << "Repeated: " << ans.second << "\n";
}
