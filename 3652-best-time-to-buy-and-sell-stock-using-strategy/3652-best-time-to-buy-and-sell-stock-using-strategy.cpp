class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = -1LL * strategy[i] * prices[i];
            B[i] = 1LL * (1 - strategy[i]) * prices[i];
        }

        long long sumA = 0, sumB = 0;

        for (int i = 0; i < half; i++) sumA += A[i];
        for (int i = half; i < k; i++) sumB += B[i];

        long long maxDelta = sumA + sumB;

        for (int l = 1; l + k - 1 < n; l++) {
            sumA -= A[l - 1];
            sumA += A[l + half - 1];

            sumB -= B[l + half - 1];
            sumB += B[l + k - 1];

            maxDelta = max(maxDelta, sumA + sumB);
        }

        return baseProfit + max(0LL, maxDelta);
    }
};
