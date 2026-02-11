class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<int> freq(100001);

        for(int left = 0; left < n; left++) {

            if(n - left <= ans) break;   // pruning

            int distinctEven = 0;
            int distinctOdd = 0;

            for(int i = 0; i <= 100000; i++)
                freq[i] = 0;

            for(int right = left; right < n; right++) {

                if(freq[nums[right]] == 0) {
                    if(nums[right] % 2 == 0)
                        distinctEven++;
                    else
                        distinctOdd++;
                }

                freq[nums[right]]++;

                if(distinctEven == distinctOdd)
                    ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};
