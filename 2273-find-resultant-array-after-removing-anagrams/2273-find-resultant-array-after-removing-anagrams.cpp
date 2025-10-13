class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        for (const string& w : words) {
            if (result.empty()) {
                result.push_back(w);
            } else {
                string prev_sorted = result.back();
                string curr_sorted = w;
                sort(prev_sorted.begin(), prev_sorted.end());
                sort(curr_sorted.begin(), curr_sorted.end());
                if (prev_sorted == curr_sorted) {

                    continue;
                } else {
                    result.push_back(w);
                }
            }
        }
        return result;
    }
};
