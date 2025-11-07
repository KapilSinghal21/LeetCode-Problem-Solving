class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        // Compute initial power for every city using sliding window
        vector<long long> power(n, 0);
        long long window = 0;
        // initial window covering indices [0 .. r]
        for (int i = 0; i < min(n, r + 1); ++i)
            window += stations[i];
        // fill power[0]
        power[0] = window;
        for (int i = 1; i < n; ++i) {
            // window should cover [i-r .. i+r]
            int addIdx = i + r;
            int remIdx = i - r - 1;
            if (addIdx < n)
                window += stations[addIdx];
            if (remIdx >= 0)
                window -= stations[remIdx];
            power[i] = window;
        }

        // Binary search on answer (minimum power)
        long long lo = 0, hi = (long long)1e18, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canAchieve(power, r, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }

private:
    bool canAchieve(const vector<long long>& power, int r, long long k,
                    long long target) {
        int n = power.size();
        vector<long long> diff(n + 1, 0); // diff array for range adds on cities
        long long curAdd = 0; // current cumulative addition affecting city i
        long long used = 0;

        for (int i = 0; i < n; ++i) {
            curAdd += diff[i]; // apply any diff that starts/ends here
            long long curPower = power[i] + curAdd;
            if (curPower < target) {
                long long need = target - curPower;
                used += need;
                if (used > k)
                    return false;

                curAdd += need;
                int endIdx = i + 2 * r + 1; // after R = i + 2r
                if (endIdx < n)
                    diff[endIdx] -= need;
            }
        }
        return true;
    }
};
