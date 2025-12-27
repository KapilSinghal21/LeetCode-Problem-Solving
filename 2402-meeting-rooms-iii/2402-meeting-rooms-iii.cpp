class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        // Min-heap for occupied rooms {endTime, room}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> occupied;

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Free rooms that are done before current meeting
            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            if (!available.empty()) {
                // Assign meeting to available room
                int room = available.top();
                available.pop();
                occupied.push({end, room});
                count[room]++;
            } else {
                // Delay meeting
                auto [finishTime, room] = occupied.top();
                occupied.pop();
                occupied.push({finishTime + duration, room});
                count[room]++;
            }
        }

        // Find room with maximum meetings
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
