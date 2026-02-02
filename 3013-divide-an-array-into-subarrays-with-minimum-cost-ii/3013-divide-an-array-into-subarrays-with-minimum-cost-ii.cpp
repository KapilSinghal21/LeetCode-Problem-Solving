class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 2;  // how many elements we must pick from window

        multiset<int> small, large;   // small = k-2 smallest
        long long sumSmall = 0;

        auto add = [&](int x) {
            small.insert(x);
            sumSmall += x;
            if ((int)small.size() > need) {
                auto it = prev(small.end());  // largest in small
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto it2 = large.begin();  // smallest in large
                    sumSmall += *it2;
                    small.insert(*it2);
                    large.erase(it2);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // Initial window for i1 = 1 → indices [2, 1+dist]
        for (int i = 2; i <= min(n - 1, 1 + dist); ++i) {
            add(nums[i]);
        }

        long long ans = LLONG_MAX;

        for (int i1 = 1; i1 < n; ++i1) {
            if ((int)small.size() == need) {
                ans = min(ans, (long long)nums[0] + nums[i1] + sumSmall);
            }

            int outIdx = i1 + 1;
            int inIdx  = i1 + dist + 1;

            if (outIdx < n) remove(nums[outIdx]);
            if (inIdx < n)  add(nums[inIdx]);
        }

        return ans;
    }
};
