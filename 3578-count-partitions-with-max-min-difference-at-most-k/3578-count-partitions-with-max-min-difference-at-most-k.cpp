#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), prefix(n + 2, 0); // prefix[i] = sum of dp[0..i-1]
        dp[0] = 1;
        prefix[1] = 1;

        deque<int> maxDeque, minDeque;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // Maintain max deque
            while (!maxDeque.empty() && nums[r] > nums[maxDeque.back()]) maxDeque.pop_back();
            maxDeque.push_back(r);
            // Maintain min deque
            while (!minDeque.empty() && nums[r] < nums[minDeque.back()]) minDeque.pop_back();
            minDeque.push_back(r);

            // Move left pointer until window [l..r] is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > k) {
                l++;
                if (maxDeque.front() < l) maxDeque.pop_front();
                if (minDeque.front() < l) minDeque.pop_front();
            }

            // dp[r+1] = sum of dp[l..r] = prefix[r+1] - prefix[l]
            dp[r+1] = (prefix[r+1] - prefix[l] + MOD) % MOD;

            // Update prefix sum
            prefix[r+2] = (prefix[r+1] + dp[r+1]) % MOD;
        }

        return dp[n];
    }
};
