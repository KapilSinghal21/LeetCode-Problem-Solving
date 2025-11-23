class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> mod1, mod2;

        for(int n : nums){
            sum += n;
            if(n % 3 == 1) mod1.push_back(n);
            else if(n % 3 == 2) mod2.push_back(n);
        }

        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if(sum % 3 == 0) return sum;

        int ans = 0;

        if(sum % 3 == 1){
            int op1 = mod1.size() >= 1 ? sum - mod1[0] : 0;
            int op2 = mod2.size() >= 2 ? sum - mod2[0] - mod2[1] : 0;
            ans = max(op1, op2);
        }
        else { // sum % 3 == 2
            int op1 = mod2.size() >= 1 ? sum - mod2[0] : 0;
            int op2 = mod1.size() >= 2 ? sum - mod1[0] - mod1[1] : 0;
            ans = max(op1, op2);
        }

        return ans;
    }
};
