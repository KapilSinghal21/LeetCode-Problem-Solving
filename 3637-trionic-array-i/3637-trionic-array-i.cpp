class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // ---- Phase 1: strictly increasing ----
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // p cannot be 0 or last-2
        if (i == 0 || i >= n - 2) return false;

        // ---- Phase 2: strictly decreasing ----
        int decStart = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        // must actually decrease and leave space for last increase
        if (i == decStart || i == n - 1) return false;

        // ---- Phase 3: strictly increasing ----
        int inc2Start = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // must have final increasing segment and reach end
        if (i == inc2Start) return false;

        return i == n - 1;
    }
};
