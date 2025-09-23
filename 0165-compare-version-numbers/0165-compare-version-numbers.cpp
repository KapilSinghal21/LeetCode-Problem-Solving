class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        
        while (i < n1 || j < n2) {
            long v1 = 0, v2 = 0;
            
            // read next number from version1
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                ++i;
            }
            // read next number from version2
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                ++j;
            }
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            
            // skip the dots
            ++i;
            ++j;
        }
        return 0;
    }
};
