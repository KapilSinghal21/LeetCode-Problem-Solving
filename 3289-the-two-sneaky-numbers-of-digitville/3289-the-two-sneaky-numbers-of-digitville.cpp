class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        vector<int> freq(n, 0);
        vector<int> ans;
        for (int x : nums) {
            if (++freq[x] == 2)
                ans.push_back(x);
        }
        return ans;
    }
};
