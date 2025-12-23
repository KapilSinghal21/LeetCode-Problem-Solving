class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start time
        sort(events.begin(), events.end());

        int n = events.size();

        // Step 2: Create suffix maximum array
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int answer = 0;

        // Step 3: Try each event as first event
        for (int i = 0; i < n; i++) {
            int currValue = events[i][2];
            int endTime = events[i][1];

            // Binary search for next event whose start >= endTime + 1
            int left = i + 1, right = n - 1;
            int index = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (events[mid][0] >= endTime + 1) {
                    index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // If second event exists, add its best value
            if (index != -1) {
                currValue += suffixMax[index];
            }

            answer = max(answer, currValue);
        }

        return answer;
    }
};
