class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int start = 0; start < n; start++) {
            if (nums[start] != 0) continue;

            // Try both directions: -1 (left) and +1 (right)
            for (int dir : {-1, 1}) {
                vector<int> temp = nums;
                int curr = start;
                int d = dir;

                while (curr >= 0 && curr < n) {
                    if (temp[curr] == 0) {
                        curr += d;
                    } else {
                        temp[curr]--;
                        d = -d;
                        curr += d;
                    }
                }

                // Check if all elements became 0
                bool allZero = true;
                for (int x : temp) {
                    if (x != 0) {
                        allZero = false;
                        break;
                    }
                }

                if (allZero) count++;
            }
        }

        return count;
    }
};
