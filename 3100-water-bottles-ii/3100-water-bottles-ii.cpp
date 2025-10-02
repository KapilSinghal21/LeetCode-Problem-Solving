class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        int empties = numBottles;
        
        while (empties >= numExchange) {
            empties -= numExchange;   // spend empties
            numExchange++;            // exchange rate increases
            drunk++;                  // drink new full bottle
            empties++;                // now it's empty
        }
        
        return drunk;
    }
};
