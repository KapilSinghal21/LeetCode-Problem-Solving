class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int need = 1 << k;                 // total possible codes
        vector<bool> seen(need, false);

        int mask = need - 1;                // keeps last k bits
        int hash = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            // shift left & add current bit
            hash = ((hash << 1) & mask) | (s[i] - '0');

            // start checking once window reaches size k
            if (i >= k - 1) {
                if (!seen[hash]) {
                    seen[hash] = true;
                    count++;
                    if (count == need) return true; // early exit
                }
            }
        }

        return false;
    }
};