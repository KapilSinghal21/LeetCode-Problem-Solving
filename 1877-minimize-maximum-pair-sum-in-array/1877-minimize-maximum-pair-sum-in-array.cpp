class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // Step 1: sort
        
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int maxPairSum = 0;
        
        // Step 2: pair smallest with largest
        while (left < right) {
            int currentSum = nums[left] + nums[right];
            maxPairSum = max(maxPairSum, currentSum);
            
            left++;
            right--;
        }
        
        return maxPairSum;
    }
};
