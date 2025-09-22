class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        for (int x : nums) freq[x]++;

        int maxFreq = 0, total = 0;
        for (int f : freq) maxFreq = max(maxFreq, f);

        for (int f : freq) if (f == maxFreq) total += f;
        return total;
    }
};
