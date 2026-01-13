class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = 0;

        for (auto &s : squares) {
            total += 1.0 * s[2] * s[2];
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        double target = total / 2.0;

        auto areaBelow = [&](double h) {
            double area = 0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (h <= y) continue;
                else if (h >= y + l) area += l * l;
                else area += l * (h - y);
            }
            return area;
        };

        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
