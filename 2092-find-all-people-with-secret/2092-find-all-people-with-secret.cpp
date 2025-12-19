class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rankv[px] < rankv[py]) swap(px, py);
        parent[py] = px;
        if (rankv[px] == rankv[py]) rankv[px]++;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Initially share secret
        unite(0, firstPerson);

        // Sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;

            // Union all meetings at same time
            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }

            // Rollback those not connected to person 0
            for (int p : people) {
                if (find(p) != find(0)) {
                    parent[p] = p;
                }
            }

            i = j;
        }

        // Collect result
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                ans.push_back(i);
        }
        return ans;
    }
};
