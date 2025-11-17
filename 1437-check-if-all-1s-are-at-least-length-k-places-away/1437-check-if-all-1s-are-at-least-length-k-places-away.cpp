class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;  // stores index of previous 1
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last - 1 < k) {
                    return false;
                }
                last = i;  // update last seen position
            }
        }
        return true;
    }
};
