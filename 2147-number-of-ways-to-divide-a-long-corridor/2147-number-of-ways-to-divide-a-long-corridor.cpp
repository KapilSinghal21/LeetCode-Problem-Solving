class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        
        // Count total seats
        int totalSeats = 0;
        for (char c : corridor) {
            if (c == 'S') totalSeats++;
        }
        
        // Invalid cases
        if (totalSeats == 0 || totalSeats % 2 == 1) return 0;
        
        long long ways = 1;
        int seatCount = 0;
        int plantsBetween = 0;
        bool countingPlants = false;
        
        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                
                // Finished one section of 2 seats
                if (seatCount % 2 == 0) {
                    countingPlants = true;
                }
                // Starting next section
                else if (seatCount > 2) {
                    ways = (ways * (plantsBetween + 1)) % MOD;
                    plantsBetween = 0;
                }
            } 
            else if (countingPlants) {
                plantsBetween++;
            }
        }
        
        return ways;
    }
};
