#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int i, vector<int>& candidates, int target, vector<int>& curr) {
        // Base case: valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Invalid case
        if (i == candidates.size() || target < 0) {
            return;
        }

        // Choice 1: Take current element
        curr.push_back(candidates[i]);
        dfs(i, candidates, target - candidates[i], curr);
        curr.pop_back();  // backtrack

        // Choice 2: Skip current element
        dfs(i + 1, candidates, target, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        dfs(0, candidates, target, curr);
        return ans;
    }
};
