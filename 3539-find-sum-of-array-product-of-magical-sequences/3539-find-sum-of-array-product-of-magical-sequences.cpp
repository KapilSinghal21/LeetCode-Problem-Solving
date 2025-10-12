class Solution {
public:
    const int MOD = 1e9 + 7;

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        // dp[mask] = sum of products for sequences of length 'step' using distinct indices represented by 'mask'
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;

        for (int step = 0; step < m; ++step) {
            vector<long long> ndp(1 << n, 0);
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (dp[mask] == 0) continue;
                for (int i = 0; i < n; ++i) {
                    long long newMask = mask | (1 << i); // Correctly sets the i-th bit
                    long long newVal = dp[mask] * nums[i] % MOD;
                    ndp[newMask] = (ndp[newMask] + newVal) % MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) == k) {
                ans = (ans + dp[mask]) % MOD;
            }
        }
        return ans;
    }
};