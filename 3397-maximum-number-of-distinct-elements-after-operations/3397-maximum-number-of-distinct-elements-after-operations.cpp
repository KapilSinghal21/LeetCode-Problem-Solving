class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;
        int count = 0;
        for (auto x : nums) {
            long long val = max((long long)x - k, last + 1);
            if (val <= (long long)x + k) {
                count++;
                last = val;
            }
        }
        return count;
    }
};
