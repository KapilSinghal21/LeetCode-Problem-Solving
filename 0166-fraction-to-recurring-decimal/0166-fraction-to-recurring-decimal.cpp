class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        
        string ans;
        // Sign
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');
        
        // Work with absolute values
        long long n = llabs(numerator), d = llabs(denominator);
        
        // Integer part
        ans += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return ans;   // No fractional part
        
        ans.push_back('.');
        unordered_map<long long, int> pos;  // remainder -> position in string
        
        while (rem) {
            if (pos.count(rem)) {   // repeating starts
                ans.insert(pos[rem], "(");
                ans.push_back(')');
                break;
            }
            pos[rem] = ans.size();
            rem *= 10;
            ans.push_back('0' + (rem / d));
            rem %= d;
        }
        return ans;
    }
};
