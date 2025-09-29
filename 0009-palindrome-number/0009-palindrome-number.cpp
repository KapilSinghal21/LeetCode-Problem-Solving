class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 (but not 0 itself) can’t be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;
        // Reverse only half of the number
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // If length is odd, rev/10 removes the middle digit
        return x == rev || x == rev / 10;
    }
};
