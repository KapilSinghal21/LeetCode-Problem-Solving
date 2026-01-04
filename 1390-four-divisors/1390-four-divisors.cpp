class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            vector<int> divisors;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    divisors.push_back(i);
                    if (i != x / i)
                        divisors.push_back(x / i);
                }
            }

            if (divisors.size() == 4) {
                int sum = 0;
                for (int d : divisors)
                    sum += d;
                ans += sum;
            }
        }

        return ans;
    }
};
