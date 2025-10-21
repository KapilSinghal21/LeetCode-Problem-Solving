class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        int mn = *min_element(nums.begin(), nums.end()) - k;
        int mx = *max_element(nums.begin(), nums.end()) + k;
        // shift to non-negative indices
        int offset = -mn;
        int len = mx - mn + 1;
        vector<int> diff(len + 1, 0);
        vector<int> cnt(len, 0);

        for (int x : nums) {
            int l = x - k;
            int r = x + k;
            diff[l + offset] += 1;
            if (r + offset + 1 < (int)diff.size()) diff[r + offset + 1] -= 1;
            cnt[x + offset] += 1;
        }

        // build cover array
        vector<int> cover(len, 0);
        int running = 0;
        for (int i = 0; i < len; ++i) {
            running += diff[i];
            cover[i] = running;
        }

        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int possible = min(cover[i], cnt[i] + numOperations);
            ans = max(ans, possible);
        }
        return ans;
    }
};