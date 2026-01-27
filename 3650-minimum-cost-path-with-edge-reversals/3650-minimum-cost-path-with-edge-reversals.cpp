class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            
            // Original edge
            adj[u].push_back({v, w});
            
            // Reversal option (using switch at v)
            adj[v].push_back({u, 2 * w});
        }

        // Dijkstra
        const long long INF = LLONG_MAX;
        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &[next, w] : adj[node]) {
                long long newCost = cost + w;
                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    pq.push({newCost, next});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};
