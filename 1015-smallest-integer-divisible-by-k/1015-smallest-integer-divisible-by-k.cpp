class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k has factor 2 or 5, impossible
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int remainder = 1 % k;
        int length = 1;

        // At most k iterations by pigeonhole principle
        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % k;
            length++;
        }

        return length;
    }
};
