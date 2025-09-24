class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int x : nums)
            if ((int)log10(x) % 2) ++cnt;   // log10 gives digits-1
        return cnt;
    }
};
