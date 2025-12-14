class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        vector<int> seats;
        
        // Store positions of all seats
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }
        
        int totalSeats = seats.size();
        
        // Invalid cases
        if (totalSeats == 0 || totalSeats % 2 == 1) {
            return 0;
        }
        
        long long ways = 1;
        
        // Process gaps between sections
        for (int i = 2; i < totalSeats; i += 2) {
            int gap = seats[i] - seats[i - 1] - 1;
            ways = (ways * (gap + 1)) % MOD;
        }
        
        return ways;
    }
};
