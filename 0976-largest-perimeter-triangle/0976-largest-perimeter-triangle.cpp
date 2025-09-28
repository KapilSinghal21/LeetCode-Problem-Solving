class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());             // ascending sort is slightly faster
        for (int i = nums.size() - 1; i >= 2; --i) {
            if (nums[i-1] + nums[i-2] > nums[i]) {  // triangle inequality
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }
};
