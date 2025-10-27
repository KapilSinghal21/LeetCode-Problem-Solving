class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devices; 
        
        // Count number of '1's in each row that has at least one device
        for (auto& row : bank) {
            int count = count_if(row.begin(), row.end(), [](char c){ return c == '1'; });
            if (count > 0)
                devices.push_back(count);
        }

        int totalBeams = 0;
        
        // Multiply consecutive non-empty rows
        for (int i = 1; i < devices.size(); ++i) {
            totalBeams += devices[i - 1] * devices[i];
        }

        return totalBeams;
    }
};
