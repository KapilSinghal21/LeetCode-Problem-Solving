class Solution {
public:
    // method name the harness expects
    int specialTriplets(vector<int>& nums) {
        return countTriplets(nums);
    }

    // core implementation (O(n))
    int countTriplets(vector<int>& nums) {
        const long long MOD = 1000000007LL;
        int n = (int)nums.size();
        if (n < 3) return 0;

        // maximum value in nums is <= 1e5 so 2*x <= 2e5
        const int MAXV = 200000;
        vector<long long> left(MAXV + 1, 0), right(MAXV + 1, 0);

        for (int x : nums) {
            if (x >= 0 && x <= MAXV) right[x]++;
        }

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            // move current from right to be the center j
            right[x]--;
            int target = x * 2;
            if (target <= MAXV) {
                ans = (ans + (left[target] * right[target]) % MOD) % MOD;
            }
            left[x]++;
        }

        return (int)ans;
    }
};
