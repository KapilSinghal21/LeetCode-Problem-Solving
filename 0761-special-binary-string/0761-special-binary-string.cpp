class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // Found a special substring
            if (count == 0) {
                // Recursively solve inside
                string inner = s.substr(start + 1, i - start - 1);
                string optimized = "1" + makeLargestSpecial(inner) + "0";
                blocks.push_back(optimized);

                start = i + 1;
            }
        }

        // Sort descending for lexicographically largest
        sort(blocks.begin(), blocks.end(), greater<string>());

        // Join
        string result;
        for (auto &b : blocks)
            result += b;

        return result;
    }
};