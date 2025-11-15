class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> P(n+1, 0), Z(n+1, 0);

        for (int i = 0; i < n; i++) {
            P[i+1] = P[i] + (s[i] == '1');
            Z[i+1] = Z[i] + (s[i] == '0');
        }

        int B = sqrt(n) + 2;
        vector<vector<int>> bucket(n+1);

        // group indices by zero count
        for (int i = 0; i <= n; i++)
            bucket[Z[i]].push_back(P[i]);

        // sort each bucket
        for (int i = 0; i <= n; i++)
            sort(bucket[i].begin(), bucket[i].end());

        long long ans = 0;

        for (int z = 0; z <= n; z++) {
            for (int d = 0; d <= B && z + d <= n; d++) {
                long long need = -(long long)d * d;

                // count pairs (i,j) where:
                // Z[j] = z+d, Z[i] = z
                // P[j] - P[i] >= d^2  ⇔  P[i] <= P[j] - d^2
                for (int Pj : bucket[z + d]) {
                    long long limit = Pj - 1LL * d * d;
                    ans += upper_bound(bucket[z].begin(), bucket[z].end(), limit)
                           - bucket[z].begin();
                }
            }
        }

        return ans - n - 1; // remove empty substring and self-pairs
    }
};
