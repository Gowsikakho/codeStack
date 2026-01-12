#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, int st, vector<int>& temp) {
        ans.push_back(temp);

        for (int i = st; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > st && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            helper(nums, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // mandatory
        vector<int> temp;
        helper(nums, 0, temp);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets are:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
