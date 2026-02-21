class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Bitmask for primes up to 20 bits:
        // primes = {2,3,5,7,11,13,17,19}
        int primeMask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
                        (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);

        int ans = 0;
        for (int i = left; i <= right; ++i) {
            int bits = __builtin_popcount(i);
            if (primeMask & (1 << bits))
                ++ans;
        }
        return ans;
    }
};