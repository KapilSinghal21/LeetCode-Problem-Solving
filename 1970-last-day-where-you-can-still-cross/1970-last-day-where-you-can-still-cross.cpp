class Solution {
public:
    int parent[40005], rankv[40005];

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rankv[x] < rankv[y])
            parent[x] = y;
        else if (rankv[x] > rankv[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rankv[x]++;
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n;
        int BOTTOM = n + 1;

        for (int i = 0; i < n + 2; i++) {
            parent[i] = i;
            rankv[i] = 0;
        }

        vector<vector<int>> grid(row, vector<int>(col, 0));
        vector<int> dirs = {0, 1, 0, -1, 0};

        for (int day = n - 1; day >= 0; day--) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 1;

            int id = r * col + c;

            if (r == 0) unite(id, TOP);
            if (r == row - 1) unite(id, BOTTOM);

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc]) {
                    unite(id, nr * col + nc);
                }
            }

            if (find(TOP) == find(BOTTOM))
                return day;
        }

        return 0;
    }
};
