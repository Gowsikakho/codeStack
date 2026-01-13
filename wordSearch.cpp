#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool dfs(int i, int j, vector<vector<char>>& bd,
             const string& wd, int ind) {

        // Base case: entire word matched
        if (ind == wd.size()) return true;

        // Invalid state checks (boundary + mismatch)
        if (i < 0 || i >= bd.size() ||
            j < 0 || j >= bd[0].size() ||
            bd[i][j] != wd[ind]) {
            return false;
        }

        char temp = bd[i][j];
        bd[i][j] = '*';  // mark visited

        for (int d = 0; d < 4; d++) {
            if (dfs(i + dr[d], j + dc[d], bd, wd, ind + 1)) {
                bd[i][j] = temp; // backtrack
                return true;
            }
        }

        bd[i][j] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& bd, string word) {
        int n = bd.size(), m = bd[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, bd, word, 0))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution sol;
    bool result = sol.exist(board, word);

    if (result)
        cout << "Word exists in the board\n";
    else
        cout << "Word does not exist in the board\n";

    return 0;
}
