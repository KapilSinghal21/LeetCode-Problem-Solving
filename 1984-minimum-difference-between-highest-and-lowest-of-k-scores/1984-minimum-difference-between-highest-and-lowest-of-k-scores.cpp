class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // If only one student, difference is 0
        if (k == 1) return 0;
        
        // Step 1: Sort the scores
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = INT_MAX;
        
        // Step 2: Sliding window of size k
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = nums[i + k - 1] - nums[i];
            ans = min(ans, diff);
        }
        
        return ans;
    }
};
