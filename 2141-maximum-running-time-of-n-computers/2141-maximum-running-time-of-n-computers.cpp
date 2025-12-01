class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (long long b : batteries) sum += b;

        long long left = 0, right = sum / n;   // maximum possible time
        long long ans = 0;

        while (left <= right) {
            long long t = (left + right) / 2;

            long long usable = 0;
            for (long long b : batteries) 
                usable += min(b, t);

            if (usable >= t * n) {
                ans = t;
                left = t + 1;
            } else {
                right = t - 1;
            }
        }
        return ans;
    }
};
