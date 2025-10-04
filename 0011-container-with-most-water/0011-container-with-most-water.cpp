class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int hLeft = height[left];
            int hRight = height[right];
            int h = (hLeft < hRight) ? hLeft : hRight;
            int area = h * (right - left);

            if (area > maxWater) maxWater = area;

            if (hLeft < hRight) {
                ++left;
            } else {
                --right;
            }
        }
        return maxWater;
    }
};
