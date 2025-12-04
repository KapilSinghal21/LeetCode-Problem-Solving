class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        // Skip L's on the left edge
        while (left < n && s[left] == 'L') left++;

        // Skip R's on the right edge
        while (right >= 0 && s[right] == 'R') right--;

        int collisions = 0;

        // Count all moving cars inside the remaining segment
        for (int i = left; i <= right; i++) {
            if (s[i] == 'L' || s[i] == 'R')
                collisions++;
        }
        return collisions;
    }
};
