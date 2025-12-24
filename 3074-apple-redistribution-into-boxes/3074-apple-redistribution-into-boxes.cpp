class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;

        // Sum all apples
        for (int a : apple) {
            totalApples += a;
        }

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int currentCapacity = 0;
        int boxes = 0;

        // Pick boxes until we can store all apples
        for (int cap : capacity) {
            currentCapacity += cap;
            boxes++;

            if (currentCapacity >= totalApples) {
                break;
            }
        }

        return boxes;
    }
};
