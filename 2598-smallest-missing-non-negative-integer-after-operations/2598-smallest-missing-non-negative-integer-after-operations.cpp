class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            freq[rem]++;
        }

        int x = 0;
        while (true) {
            int rem = x % value;
            if (freq[rem] > 0) {
                freq[rem]--;
            } else {
                return x;
            }
            x++;
        }
    }
};
