class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);
        
        long long pref = 0;
        long long ans = LLONG_MIN;
        
        // Prefix index 0 has sum 0 and mod = 0
        minPref[0] = 0;
        
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = (i + 1) % k;
            
            // Compute possible maximum using earlier minimum prefix with same mod
            if (minPref[mod] != LLONG_MAX) {
                ans = max(ans, pref - minPref[mod]);
            }
            
            // Update minimum prefix for this mod
            minPref[mod] = min(minPref[mod], pref);
        }
        
        return ans;
    }
};
