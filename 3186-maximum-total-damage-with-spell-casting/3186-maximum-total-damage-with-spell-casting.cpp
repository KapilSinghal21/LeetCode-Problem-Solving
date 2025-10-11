class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> sum;
        for (long long p : power)
            sum[p] += p;  

        vector<long long> vals;
        vals.reserve(sum.size());
        for (auto &it : sum)
            vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);
        dp[0] = sum[vals[0]];

        for (int i = 1; i < n; i++) {
            long long include = sum[vals[i]];

        
            int j = i - 1;
            while (j >= 0 && vals[i] - vals[j] <= 2) j--;

            if (j >= 0) include += dp[j];  

            dp[i] = max(dp[i - 1], include);
        }

        return dp[n - 1];
    }
};
