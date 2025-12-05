class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int S = 0;
        for (int x : nums) S += x;

        // If total sum is odd → no partition can give even difference
        if (S % 2 != 0) return 0;

        // Otherwise all i from 0 to n-2 are valid
        return n - 1;
    }
};
