class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int globalMin = arrays[0].front();
        int globalMax = arrays[0].back();

        for (int i = 1; i < arrays.size(); ++i) {
            int curMin = arrays[i].front();
            int curMax = arrays[i].back();
            // pick farthest pair between this array and previous arrays
            ans = max(ans, max(abs(curMax - globalMin), abs(globalMax - curMin)));
            // update global extremes
            globalMin = min(globalMin, curMin);
            globalMax = max(globalMax, curMax);
        }
        return ans;
    }
};
