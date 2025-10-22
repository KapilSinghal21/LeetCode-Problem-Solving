#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            // shrink window while range exceeds allowed modifications
            while (nums[r] - nums[l] > 2 * k) {
                ++l;
            }
            int windowSize = r - l + 1;
            // we can only modify up to numOperations distinct indices
            res = max(res, min(windowSize, numOperations + 1));
        }
        return res;
    }
};
