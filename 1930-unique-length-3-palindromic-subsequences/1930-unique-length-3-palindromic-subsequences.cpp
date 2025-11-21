class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Collect first and last occurrences
        for(int i = 0; i < n; i++){
            int c = s[i] - 'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        int count = 0;
        
        // For each possible outer character
        for(int c = 0; c < 26; c++){
            if(first[c] != -1 && last[c] != -1 && first[c] < last[c]) {
                unordered_set<char> middle;
                for(int i = first[c] + 1; i < last[c]; i++){
                    middle.insert(s[i]);
                }
                count += middle.size();
            }
        }
        
        return count;
    }
};
