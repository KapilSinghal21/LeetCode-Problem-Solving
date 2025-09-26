class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = 0;

        // iterate from largest side downwards
        for (int k = n - 1; k > 1; --k) {
            // skip zeros quickly (cannot form triangle)
            if (nums[k] == 0) continue;

            int i = 0, j = k - 1;
            // two-pointer search
            while (i < j) {
                // if smallest + second largest already too small, move i up
                if (nums[i] + nums[j] <= nums[k]) {
                    ++i;
                } else {
                    ans += j - i;  // all pairs [i..j-1] work with nums[j]
                    --j;
                }
            }
        }
        return ans;
    }
};
