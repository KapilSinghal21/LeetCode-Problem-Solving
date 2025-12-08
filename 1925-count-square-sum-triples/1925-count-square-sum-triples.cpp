class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            int c2 = c * c;
            for (int a = 1; a < c; ++a) {
                int b2 = c2 - a * a;
                if (b2 <= 0) continue;
                int b = (int)std::sqrt(b2);
                if (b >= 1 && b <= n && b * b == b2) {
                    ++ans; // count the ordered triple (a, b, c)
                }
            }
        }
        return ans;
    }
};
