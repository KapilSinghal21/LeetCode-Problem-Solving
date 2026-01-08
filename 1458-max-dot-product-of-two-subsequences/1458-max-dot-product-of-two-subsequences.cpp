class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        const long long NEG_INF = -1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, NEG_INF));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long long product = (long long)nums1[i - 1] * nums2[j - 1];

                long long take = product + max(0LL, dp[i - 1][j - 1]);
                long long skip1 = dp[i - 1][j];
                long long skip2 = dp[i][j - 1];

                dp[i][j] = max({take, skip1, skip2});
            }
        }
        return dp[n][m];
    }
};
