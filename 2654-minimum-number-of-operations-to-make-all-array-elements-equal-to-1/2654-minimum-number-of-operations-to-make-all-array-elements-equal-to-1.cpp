class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        
        // Case 1: If there is already a 1
        if (ones > 0) return n - ones;

        // Compute overall gcd
        int g = nums[0];
        for (int x : nums) g = gcd(g, x);
        if (g != 1) return -1;  // impossible

        // Find smallest subarray with gcd = 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        // total operations = (to make one 1) + (to spread 1s)
        return (minLen - 1) + (n - 1);
    }
};
