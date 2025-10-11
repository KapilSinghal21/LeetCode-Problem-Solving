class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeSolution(vector<vector<char>>& board, int n,
                       vector<vector<string>>& ans) {  // pass by reference
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        if (rowCheck[row]) return false;
        if (upperLeftDiagonalCheck[n - 1 + col - row]) return false;
        if (bottomLeftDiagonalCheck[row + col]) return false;
        return true;
    }

    void solve(vector<vector<char>>& board, int col, int n,
               vector<vector<string>>& ans) { // pass by reference
        if (col >= n) {
            storeSolution(board, n, ans);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n - 1 + col - row] = true;
                bottomLeftDiagonalCheck[row + col] = true;

                solve(board, col + 1, n, ans);

                // backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n - 1 + col - row] = false;
                bottomLeftDiagonalCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(board, 0, n, ans);
        return ans; //  return the final answer
    }
};
