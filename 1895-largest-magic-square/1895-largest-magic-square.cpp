class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Row & Column prefix sums
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        // Diagonal prefix sums
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        auto isMagic = [&](int r, int c, int k) {
            int target = row[r][c + k] - row[r][c];

            // Rows
            for (int i = r; i < r + k; i++) {
                if (row[i][c + k] - row[i][c] != target)
                    return false;
            }

            // Columns
            for (int j = c; j < c + k; j++) {
                if (col[r + k][j] - col[r][j] != target)
                    return false;
            }

            // Diagonals
            if (diag1[r + k][c + k] - diag1[r][c] != target)
                return false;

            if (diag2[r + k][c] - diag2[r][c + k] != target)
                return false;

            return true;
        };

        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(i, j, k))
                        return k;
                }
            }
        }

        return 1;  // Every 1x1 grid is magic
    }
};
