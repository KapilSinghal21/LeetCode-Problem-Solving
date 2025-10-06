class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Min-heap: {time, x, y}
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        // Directions
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); 
            pq.pop();
            
            if (x == n - 1 && y == n - 1) return t;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }
};
