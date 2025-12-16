class Solution {
public:
    int B;
    vector<int> present, future;
    vector<vector<int>> tree;

    // memo[u][bossBought]
    vector<vector<vector<int>>> memo;
    vector<vector<bool>> vis;

    vector<int> dfs(int u, int bossBought) {
        if (vis[u][bossBought]) return memo[u][bossBought];
        vis[u][bossBought] = true;

        vector<int> dp(B + 1, 0);

        // Case 1: u is NOT bought
        for (int v : tree[u]) {
            vector<int> child = dfs(v, 0);
            vector<int> ndp(B + 1, 0);

            for (int i = 0; i <= B; i++) {
                for (int j = 0; i + j <= B; j++) {
                    ndp[i + j] = max(ndp[i + j], dp[i] + child[j]);
                }
            }
            dp = ndp;
        }

        // Case 2: u IS bought
        int cost = bossBought ? present[u] / 2 : present[u];
        int profit = future[u] - cost;

        if (profit >= 0 && cost <= B) {
            vector<int> dpBuy(B + 1, -1e9);
            dpBuy[cost] = profit;

            for (int v : tree[u]) {
                vector<int> child = dfs(v, 1);
                vector<int> ndp(B + 1, -1e9);

                for (int i = 0; i <= B; i++) {
                    if (dpBuy[i] < 0) continue;
                    for (int j = 0; i + j <= B; j++) {
                        ndp[i + j] = max(ndp[i + j], dpBuy[i] + child[j]);
                    }
                }
                dpBuy = ndp;
            }

            for (int b = 0; b <= B; b++) {
                dp[b] = max(dp[b], dpBuy[b]);
            }
        }

        return memo[u][bossBought] = dp;
    }

    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int budget
    ) {
        this->B = budget;
        this->present.assign(n + 1, 0);
        this->future.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            this->present[i] = present[i - 1];
            this->future[i] = future[i - 1];
        }

        tree.assign(n + 1, {});
        for (auto &e : hierarchy) {
            tree[e[0]].push_back(e[1]);
        }

        memo.assign(n + 1, vector<vector<int>>(2));
        vis.assign(n + 1, vector<bool>(2, false));

        vector<int> res = dfs(1, 0);
        return *max_element(res.begin(), res.end());
    }
};
