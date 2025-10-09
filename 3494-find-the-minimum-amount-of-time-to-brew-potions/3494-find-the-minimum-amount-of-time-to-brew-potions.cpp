class Solution {
public:
    long long minTime(vector<int>& speed, vector<int>& difficulty) {
        int n = speed.size(), m = difficulty.size();
        vector<long long> done(n + 1, 0);

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i)
                done[i + 1] = max(done[i + 1], done[i]) +
                              (long long)speed[i] * difficulty[j];

            for (int i = n - 1; i > 0; --i)
                done[i] = done[i + 1] - (long long)speed[i] * difficulty[j];
        }
        return done[n];
    }
};