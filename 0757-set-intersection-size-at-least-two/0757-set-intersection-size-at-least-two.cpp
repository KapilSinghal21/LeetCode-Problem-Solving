class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] > b[0]; 
            return a[1] < b[1];
        });

        int p1 = -1, p2 = -1; // last two chosen points
        int result = 0;

        for(auto &in : intervals){
            int start = in[0], end = in[1];

            bool p1_in = (p1 >= start && p1 <= end);
            bool p2_in = (p2 >= start && p2 <= end);

            if(p1_in && p2_in) continue;         // already has 2
            else if(p1_in) {                    // has only 1
                result++;
                p2 = p1;
                p1 = end;
            } else {                            // has 0
                result += 2;
                p2 = end - 1;
                p1 = end;
            }
        }
        return result;
    }
};
