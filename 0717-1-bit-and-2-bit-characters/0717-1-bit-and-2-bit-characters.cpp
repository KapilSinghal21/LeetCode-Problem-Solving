class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) { // stop before the last element
            if (bits[i] == 1)
                i += 2; // two-bit character
            else
                i += 1; // one-bit character
        }

        return i == n - 1; // did we end exactly at the last bit?
    }
};