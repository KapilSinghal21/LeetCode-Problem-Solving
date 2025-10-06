class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0}); 
        visited[0][0] = 1;
        
        vector<int> dir = {0, 1, 0, -1, 0};
        
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0], x = top[1], y = top[2];
            
            if (x == n-1 && y == n-1) return t; // reached destination
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k], ny = y + dir[k+1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; 
    }
};
