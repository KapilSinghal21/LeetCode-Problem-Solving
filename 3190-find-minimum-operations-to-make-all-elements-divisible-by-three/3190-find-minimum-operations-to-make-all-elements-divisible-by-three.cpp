class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int x : nums){
            int r = x % 3;
            ops += min(r, 3 - r);
        }
        return ops;
    }
};
