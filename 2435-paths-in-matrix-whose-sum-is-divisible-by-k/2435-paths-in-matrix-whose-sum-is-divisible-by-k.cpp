class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[j][mod] means for column j, number of paths to reach (current row, j) with sum%k = mod
        vector<vector<int>> dp(n, vector<int>(k, 0)), newdp(n, vector<int>(k, 0));

        // initialize first cell
        dp[0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            // reset newdp for this row
            for (int j = 0; j < n; j++)
                fill(newdp[j].begin(), newdp[j].end(), 0);

            for (int j = 0; j < n; j++) {
                for (int mod = 0; mod < k; mod++) {
                    if ((i == 0 && j == 0) && mod == grid[0][0] % k) {
                        newdp[j][mod] = 1;
                        continue;
                    }

                    long long ways = 0;

                    // from top
                    if (i > 0)
                        ways += dp[j][mod];

                    // from left
                    if (j > 0)
                        ways += newdp[j - 1][mod];

                    ways %= MOD;

                    if (ways > 0) {
                        int new_mod = (mod + grid[i][j]) % k;
                        newdp[j][new_mod] = (newdp[j][new_mod] + ways) % MOD;
                    }
                }
            }

            dp = newdp;  // move to next row
        }

        return dp[n - 1][0]; // sum divisible by k
    }
};
