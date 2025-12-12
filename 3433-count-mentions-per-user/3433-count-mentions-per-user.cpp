#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<int> offlineUntil(numberOfUsers, -1);

        // Sort events by timestamp (grouping by timestamp). Within same timestamp
        // order doesn't matter because we'll process OFFLINE first and MESSAGE later.
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            int ta = stoi(a[1]);
            int tb = stoi(b[1]);
            return ta < tb;
        });

        int n = events.size();
        int i = 0;
        while (i < n) {
            int t = stoi(events[i][1]);

            // 1) Bring back any users whose offlineUntil <= t
            for (int u = 0; u < numberOfUsers; ++u) {
                if (!online[u] && offlineUntil[u] <= t) {
                    online[u] = true;
                }
            }

            // find range of events with timestamp t
            int j = i;
            while (j < n && stoi(events[j][1]) == t) ++j;

            // 2) First process ALL OFFLINE events at time t
            for (int k = i; k < j; ++k) {
                if (events[k][0] == "OFFLINE") {
                    int id = stoi(events[k][2]);
                    online[id] = false;
                    offlineUntil[id] = t + 60;
                }
            }

            // 3) Then process all MESSAGE events at time t
            for (int k = i; k < j; ++k) {
                if (events[k][0] != "MESSAGE") continue;
                string msg = events[k][2];

                if (msg == "ALL") {
                    for (int u = 0; u < numberOfUsers; ++u) mentions[u]++;
                } else if (msg == "HERE") {
                    for (int u = 0; u < numberOfUsers; ++u) {
                        if (online[u]) mentions[u]++;
                    }
                } else {
                    // tokens like "id3 id1 id3"
                    stringstream ss(msg);
                    string token;
                    while (ss >> token) {
                        if (token.rfind("id", 0) == 0) {
                            int id = stoi(token.substr(2));
                            mentions[id]++;
                        }
                    }
                }
            }

            // advance to next timestamp block
            i = j;
        }

        return mentions;
    }
};
