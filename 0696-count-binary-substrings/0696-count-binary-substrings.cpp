class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;

        // Build group lengths
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        // Count valid substrings
        int result = 0;
        for (int i = 0; i < groups.size() - 1; i++) {
            result += min(groups[i], groups[i + 1]);
        }

        return result;
    }
};
