class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        
        int openN = 0;
        int seenY = 0;
        
        int minPenalty = totalY; // closing at hour 0
        int bestHour = 0;
        
        for (int j = 0; j < n; j++) {
            if (customers[j] == 'Y')
                seenY++;
            else
                openN++;
            
            int closedY = totalY - seenY;
            int penalty = openN + closedY;
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j + 1;
            }
        }
        
        return bestHour;
    }
};
