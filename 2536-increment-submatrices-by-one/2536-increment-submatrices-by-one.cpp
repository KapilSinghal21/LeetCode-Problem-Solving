class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            
            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        // Build the final matrix using prefix sums
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Row-wise prefix sum
        for (int r = 0; r < n; r++) {
            for (int c = 1; c < n; c++) {
                diff[r][c] += diff[r][c - 1];
            }
        }

        // Column-wise prefix sum
        for (int c = 0; c < n; c++) {
            for (int r = 1; r < n; r++) {
                diff[r][c] += diff[r - 1][c];
            }
        }

        // Copy into result matrix
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                mat[r][c] = diff[r][c];
            }
        }

        return mat;
    }
};
