class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> st; // monotonic increasing stack
        
        for (int x : nums) {
            if (x == 0) {
                ans += st.size();
                st.clear();
                continue;
            }

            // Remove larger elements (each removal = one operation)
            while (!st.empty() && st.back() > x) {
                st.pop_back();
                ans++;
            }

            // Add new layer if needed
            if (st.empty() || st.back() < x)
                st.push_back(x);
        }

        // Remaining layers
        ans += st.size();
        return ans;
    }
};
