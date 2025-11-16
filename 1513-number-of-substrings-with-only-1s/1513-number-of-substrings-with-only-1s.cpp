class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 0, count = 0;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                ans = (ans + (count * (count + 1) / 2)) % MOD;
                count = 0;
            }
        }

        // Add last counted block if string ends with '1'
        ans = (ans + (count * (count + 1) / 2)) % MOD;

        return ans;
    }
};
