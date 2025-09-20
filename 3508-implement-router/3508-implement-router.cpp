class Router {
    int limit;
    std::deque<std::tuple<int,int,int>> q;            // FIFO queue
    std::unordered_set<string> seen;                  // detect duplicates
    std::unordered_map<int, std::vector<int>> times;  // dest -> sorted timestamps

    string key(int s,int d,int t){
        return to_string(s)+'#'+to_string(d)+'#'+to_string(t);
    }
    void evict() {
        auto [s,d,t] = q.front(); q.pop_front();
        seen.erase(key(s,d,t));
        auto &v = times[d];
        // oldest packet always at front of v for that dest (timestamps increase)
        // remove t (could be not first if multiple with same timestamp)
        auto it = lower_bound(v.begin(), v.end(), t);
        if(it != v.end() && *it == t) v.erase(it);
        if(v.empty()) times.erase(d);
    }
public:
    Router(int memoryLimit): limit(memoryLimit) {}

    bool addPacket(int s,int d,int t) {
        string k = key(s,d,t);
        if(seen.count(k)) return false;      // duplicate
        if((int)q.size() == limit) evict();  // evict oldest if full
        q.emplace_back(s,d,t);
        seen.insert(k);
        times[d].push_back(t);               // append keeps vector sorted
        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [s,d,t] = q.front(); q.pop_front();
        seen.erase(key(s,d,t));
        auto &v = times[d];
        auto it = lower_bound(v.begin(), v.end(), t);
        if(it != v.end() && *it == t) v.erase(it);
        if(v.empty()) times.erase(d);
        return {s,d,t};
    }

    int getCount(int d,int L,int R) {
        if(!times.count(d)) return 0;
        const auto &v = times[d];
        auto itL = lower_bound(v.begin(), v.end(), L);
        auto itR = upper_bound(v.begin(), v.end(), R);
        return (int)(itR - itL);
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */