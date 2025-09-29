class Solution {
public:
    bool isPalindrome(int x) {
       
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        // Use long long to avoid any intermediate overflow
        long long rev = 0;
        while (x > rev) {                     // reverse only half
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev || x == rev / 10);   // works for odd and even digit counts
    }
};
