class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if (p == 2) {   // special case
                ans.push_back(-1);
                continue;
            }

            int best = INT_MAX;

            for (int bit = 0; bit < 31; bit++) {
                if (p & (1 << bit)) {
                    int x = p - (1 << bit);
                    if (x >= 0 && (x | (x + 1)) == p) {
                        best = min(best, x);
                    }
                }
            }

            ans.push_back(best == INT_MAX ? -1 : best);
        }

        return ans;
    }
};
