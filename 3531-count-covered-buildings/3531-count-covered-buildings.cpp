class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        unordered_map<int, vector<int>> rowToYs;
        unordered_map<int, vector<int>> colToXs;
        rowToYs.reserve(m*2);
        colToXs.reserve(m*2);

        // collect coordinates by row and column
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rowToYs[x].push_back(y);
            colToXs[y].push_back(x);
        }

        // sort the coordinate lists for binary search
        for (auto &it : rowToYs) {
            auto &v = it.second;
            sort(v.begin(), v.end());
        }
        for (auto &it : colToXs) {
            auto &v = it.second;
            sort(v.begin(), v.end());
        }

        int covered = 0;
        // for each building check existence of at least one smaller & one larger in row & column
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &row = rowToYs[x];
            auto posRow = lower_bound(row.begin(), row.end(), y) - row.begin();
            bool hasLeft  = (posRow > 0);                // some y' < y in same row
            bool hasRight = (posRow + 1 < (int)row.size()); // some y' > y in same row

            auto &col = colToXs[y];
            auto posCol = lower_bound(col.begin(), col.end(), x) - col.begin();
            bool hasAbove = (posCol > 0);                // some x' < x in same column
            bool hasBelow = (posCol + 1 < (int)col.size()); // some x' > x in same column

            if (hasLeft && hasRight && hasAbove && hasBelow) covered++;
        }

        return covered;
    }
};
