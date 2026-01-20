class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            int res = -1;

            // x | (x+1) is always odd
            if (p % 2 == 0) {
                ans.push_back(-1);
                continue;
            }

            for (int x = 0; x <= p; x++) {
                if ( (x | (x + 1)) == p ) {
                    res = x;
                    break; // minimum x
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};
