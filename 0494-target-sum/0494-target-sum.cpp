class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

       
        if ((target + total) % 2 != 0 || abs(target) > total) return 0;

        int subsetSum = (target + total) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; 

        for (int num : nums) {
            for (int s = subsetSum; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }
        return dp[subsetSum];
    }
};
