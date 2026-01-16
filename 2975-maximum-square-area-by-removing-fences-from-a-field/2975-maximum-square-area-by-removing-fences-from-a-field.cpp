class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hDist;

        // All possible horizontal distances
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDist.insert((long long)hFences[j] - hFences[i]);
            }
        }

        long long maxSide = 0;

        // Check vertical distances
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long d = (long long)vFences[j] - vFences[i];
                if (hDist.count(d)) {
                    maxSide = max(maxSide, d);
                }
            }
        }

        if (maxSide == 0) return -1;

        return (maxSide * maxSide) % MOD;
    }
};
