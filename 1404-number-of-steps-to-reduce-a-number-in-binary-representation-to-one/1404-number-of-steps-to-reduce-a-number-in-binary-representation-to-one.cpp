class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if (s.back() == '0') {
                // Even → divide by 2
                s.pop_back();
            } else {
                // Odd → add 1 (binary addition with carry)
                int i = s.size() - 1;
                
                // Propagate carry through trailing 1s
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    // All bits were '1' → overflow → prepend '1'
                    s = '1' + s;
                }
            }
            steps++;
        }

        return steps;
    }
};