class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        vector<long long> inc(n, NEG), dec(n, NEG), tri(n, NEG);

        long long ans = NEG;

        for (int i = 1; i < n; i++) {
            // -------- Phase 1: Increasing --------
            if (nums[i-1] < nums[i]) {
                inc[i] = max(inc[i-1] + nums[i],
                             (long long)nums[i-1] + nums[i]);
            }

            // -------- Phase 2: Decreasing --------
            if (nums[i-1] > nums[i]) {
                dec[i] = max(dec[i-1] + nums[i],
                             inc[i-1] + nums[i]);
            }

            // -------- Phase 3: Final Increasing --------
            if (nums[i-1] < nums[i]) {
                tri[i] = max(tri[i-1] + nums[i],
                             dec[i-1] + nums[i]);
            }

            ans = max(ans, tri[i]);
        }

        return ans;
    }
};
