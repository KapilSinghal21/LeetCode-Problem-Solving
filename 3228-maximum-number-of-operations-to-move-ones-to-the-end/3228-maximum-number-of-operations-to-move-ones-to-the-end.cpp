class Solution {
public:
    long long maxOperations(string s) {
        long long ones = 0;
        long long ans = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                ones++;
                i++;
            } else {
                // start of a zero-block
                if (i == 0 || s[i-1] == '1') {
                    // add number of ones to the left (if any)
                    ans += ones;
                }
                // skip whole zero block
                while (i < n && s[i] == '0') i++;
            }
        }
        return ans;
    }
};
