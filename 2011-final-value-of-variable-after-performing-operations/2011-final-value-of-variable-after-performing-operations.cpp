class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (auto &op : operations) {
            if (op[1] == '+') X++;
            else X--;
        }
        return X;
    }
};
