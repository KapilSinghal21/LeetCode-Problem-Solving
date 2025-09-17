class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < matrix[i].size(); j++) { // take care j=i bcz if we do
                                                  // j=0 the values will reverse
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse
        for (int i =0 ; i<n ; i++) {
            // to Reverse every row we have reverse function 
            reverse (matrix[i].begin() , matrix[i].end());
        }
    }
};