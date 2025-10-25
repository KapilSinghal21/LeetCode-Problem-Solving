class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;       // full weeks
        int days = n % 7;        // remaining days
        
        int total = weeks * 28 + (weeks * (weeks - 1) / 2) * 7;
        
        // Add remaining days of the last incomplete week
        int start = weeks + 1;  // starting amount on next Monday
        for (int i = 0; i < days; ++i)
            total += start + i;
        
        return total;
    }
};
