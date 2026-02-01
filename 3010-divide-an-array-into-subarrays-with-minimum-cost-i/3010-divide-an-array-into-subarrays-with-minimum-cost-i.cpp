class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // i = start of 2nd subarray
        for (int i = 1; i <= n - 2; i++) {
            // j = start of 3rd subarray
            for (int j = i + 1; j <= n - 1; j++) {
                int cost = nums[0] + nums[i] + nums[j];
                ans = min(ans, cost);
            }
        }

        return ans;
    }
};
