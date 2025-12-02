class Solution {
private:
    static const long long MOD = 1'000'000'007LL;

    int solveImpl(vector<vector<int>>& points) {
        unordered_map<long long, long long> cnt;
        cnt.reserve(points.size() * 2);

        // count points per y
        for (auto &p : points) {
            long long y = p[1];
            cnt[y]++;
        }

        // compute C(c,2) for each y with c >= 2
        vector<long long> comb;
        comb.reserve(cnt.size());
        for (auto &it : cnt) {
            long long c = it.second;
            if (c >= 2) comb.push_back(c * (c - 1) / 2);
        }

        if (comb.size() < 2) return 0;

        long long total = 0;
        long long sqsum = 0;
        for (long long x : comb) {
            long long xm = x % MOD;
            total = (total + xm) % MOD;
            sqsum = (sqsum + (xm * xm) % MOD) % MOD;
        }

        long long ans = (total * total) % MOD;
        ans = (ans - sqsum + MOD) % MOD;
        // divide by 2 modulo MOD using modular inverse of 2
        long long inv2 = (MOD + 1) / 2; // 500000004
        ans = (ans * inv2) % MOD;
        return (int)ans;
    }

public:
    // original method name provided earlier
    int numberOfPairs(vector<vector<int>>& points) {
        return solveImpl(points);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        return solveImpl(points);
    }

};
