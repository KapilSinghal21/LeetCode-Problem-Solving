class Solution {
public:
    const long long INF = 1e18;

    struct TrieNode {
        int next[26];
        int id = -1;
        TrieNode() { memset(next, -1, sizeof(next)); }
    };

    vector<TrieNode> trieS{TrieNode()}, trieT{TrieNode()};

    void insert(vector<TrieNode>& trie, const string& s, int id) {
        int node = 0;
        for (char c : s) {
            int x = c - 'a';
            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[x];
        }
        trie[node].id = id;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        int n = source.size();

        // ---- Step 1: Map patterns to ids ----
        unordered_map<string, int> idMap;
        int id = 0;

        for (auto &s : original)
            if (!idMap.count(s)) idMap[s] = id++;
        for (auto &s : changed)
            if (!idMap.count(s)) idMap[s] = id++;

        int m = id;

        // ---- Step 2: Floyd–Warshall matrix ----
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = idMap[original[i]];
            int v = idMap[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // ---- Step 3: Build tries ----
        for (auto &[s, idx] : idMap) {
            insert(trieS, s, idx);
            insert(trieT, s, idx);
        }

        // ---- Step 4: DP ----
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Case 1: same character
            if (source[i] == target[i])
                dp[i] = dp[i+1];

            int nodeS = 0, nodeT = 0;

            for (int j = i; j < n; j++) {
                int cs = source[j] - 'a';
                int ct = target[j] - 'a';

                if (nodeS == -1 || nodeT == -1) break;

                nodeS = trieS[nodeS].next[cs];
                nodeT = trieT[nodeT].next[ct];

                if (nodeS == -1 || nodeT == -1) break;

                int idS = trieS[nodeS].id;
                int idT = trieT[nodeT].id;

                if (idS != -1 && idT != -1 && dist[idS][idT] < INF) {
                    dp[i] = min(dp[i], dist[idS][idT] + dp[j+1]);
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
