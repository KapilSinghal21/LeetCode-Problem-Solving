class Solution {
public:
    static const int MOD = 1000000007;

    // Renamed to the expected function name by the judge
    int countPermutations(vector<int>& complexity) {
        int n = (int)complexity.size();
        if (n == 0) return 0;
        vector<int> mn(n);
        mn[0] = complexity[0];

        // minimum complexity seen before index i
        for (int i = 1; i < n; ++i) {
            mn[i] = min(mn[i-1], complexity[i-1]);
        }

        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            // if there is no valid parent j < i with complexity[j] < complexity[i]
            if (mn[i] >= complexity[i]) return 0;
            ans = (ans * (i - 1 + 1 - 1 + 1 - 1 + 1 )) % MOD;
        }
        return (int)ans;
    }
};
