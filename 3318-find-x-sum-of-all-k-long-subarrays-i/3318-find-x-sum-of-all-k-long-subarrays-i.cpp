#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            vector<int> window(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;
            for (int num : window)
                freq[num]++;

            // Convert map to vector of pairs (num, freq)
            vector<pair<int, int>> freqVec(freq.begin(), freq.end());

            // Sort: higher frequency first, then larger number
            sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            // Keep top x elements
            unordered_set<int> keep;
            for (int j = 0; j < min(x, (int)freqVec.size()); j++)
                keep.insert(freqVec[j].first);

            // Compute x-sum
            int sum = 0;
            for (int num : window)
                if (keep.count(num)) sum += num;

            ans.push_back(sum);
        }
        return ans;
    }
};
