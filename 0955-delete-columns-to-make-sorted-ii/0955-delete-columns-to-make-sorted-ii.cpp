class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        
        // sorted[i] = true means strs[i] < strs[i+1] is already fixed
        vector<bool> sorted(n - 1, false);
        int deletions = 0;

        // Traverse each column
        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // Check if this column breaks lexicographic order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            // If column must be deleted
            if (needDelete) {
                deletions++;
            } 
            // Otherwise, update sorted pairs
            else {
                for (int i = 0; i < n - 1; i++) {
                    if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                        sorted[i] = true;
                    }
                }
            }
        }

        return deletions;
    }
};
