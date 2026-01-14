#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    int n;

    bool isSafe(int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                solve(row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        board.assign(n, string(n, '.'));
        solve(0);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    vector<vector<string>> res = obj.solveNQueens(n);

    for (auto &solution : res) {
        for (auto &row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
