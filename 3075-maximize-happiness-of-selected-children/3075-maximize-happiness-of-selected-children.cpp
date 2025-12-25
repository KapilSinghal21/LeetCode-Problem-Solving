class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long sum = 0;

        for (int i = 0; i < k; i++) {
            // Effective happiness after i decrements
            int current = happiness[i] - i;
            if (current > 0)
                sum += current;
            else
                break; // further values will also be <= 0
        }

        return sum;
    }
};
