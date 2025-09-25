class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<int> dp = t.back();                // start from last row
        for (int r = t.size()-2; r >= 0; --r)     // go upward
            for (int c = 0; c <= r; ++c)
                dp[c] = t[r][c] + min(dp[c], dp[c+1]);
        return dp[0];
    }
};
