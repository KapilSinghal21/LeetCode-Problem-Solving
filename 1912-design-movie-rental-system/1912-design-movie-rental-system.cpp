class MovieRentingSystem {
    unordered_map<long long,int> price;                    // price for (shop,movie)
    unordered_map<int,set<pair<int,int>>> avail;           // per-movie: (price,shop)
    set<tuple<int,int,int>> rented;                        // all rented: (price,shop,movie)

    static long long key(int s,int m){ return ((long long)s<<20) | m; }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            int s=e[0], m=e[1], p=e[2];
            price[key(s,m)] = p;
            avail[m].insert({p,s});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto &st = avail[movie];
        for (auto it = st.begin(); it != st.end() && ans.size() < 5; ++it)
            ans.push_back(it->second);
        return ans;
    }

    void rent(int shop, int movie) {
        int p = price[key(shop,movie)];
        avail[movie].erase({p,shop});
        rented.insert({p,shop,movie});
    }

    void drop(int shop, int movie) {
        int p = price[key(shop,movie)];
        rented.erase({p,shop,movie});
        avail[movie].insert({p,shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it) {
            auto [p,s,m] = *it;
            res.push_back({s,m});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */