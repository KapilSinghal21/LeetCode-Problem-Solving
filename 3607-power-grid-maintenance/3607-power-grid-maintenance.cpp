class DSU {
public:
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n + 1);
        rankv.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
    }
};

class Solution {
public:
    vector<int>processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections)
            dsu.unite(e[0], e[1]);

        // Build groups of stations belonging to same connected component
        unordered_map<int, set<int>> groups;
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            groups[root].insert(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> res;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                if (online[x]) {
                    res.push_back(x);
                } else {
                    if (groups[root].empty())
                        res.push_back(-1);
                    else
                        res.push_back(*groups[root].begin());
                }
            } else { // type == 2
                if (online[x]) {
                    online[x] = false;
                    groups[root].erase(x);
                }
            }
        }
        return res;
    }
};
