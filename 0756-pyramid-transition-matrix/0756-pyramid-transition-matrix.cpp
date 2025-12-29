class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        vector<string> nextRows;
        buildNextRows(bottom, 0, "", nextRows);

        for (string &row : nextRows) {
            if (dfs(row)) return memo[bottom] = true;
        }

        return memo[bottom] = false;
    }

    void buildNextRows(string &bottom, int idx, string curr, vector<string> &nextRows) {
        if (idx == bottom.size() - 1) {
            nextRows.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNextRows(bottom, idx + 1, curr + c, nextRows);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
