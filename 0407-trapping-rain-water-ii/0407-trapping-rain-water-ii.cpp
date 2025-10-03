class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; 

        using Cell = pair<int, pair<int,int>>; 
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all border cells into priority queue
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][n-1], {i,n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0,j}});
            pq.push({heightMap[m-1][j], {m-1,j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        // Directions: up, down, left, right
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int water = 0;

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // If neighbor lower than current boundary, water trapped
                    water += max(0, h - heightMap[nx][ny]);
                    // Push updated height (max of current boundary and neighbor)
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return water;
    }
};
