class TaskManager {
    // For each taskId → (userId, priority)
    unordered_map<int, pair<int,long long>> info;

    // Max-heap behavior: sort by priority desc, then taskId desc.
    struct Cmp {
        bool operator()(const tuple<long long,int,int>& a,
                        const tuple<long long,int,int>& b) const {
            if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // higher priority first
            return get<1>(a) > get<1>(b);                             // if tie, higher taskId first
        }
    };

    // set stores (priority, taskId, userId)
    set<tuple<long long,int,int>, Cmp> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int user = t[0], id = t[1]; long long pr = t[2];
            info[id] = {user, pr};
            pq.insert({pr, id, user});
        }
    }

    void add(int userId, int taskId, int priority) {
        info[taskId] = {userId, priority};
        pq.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [user, oldPr] = info[taskId];
        pq.erase({oldPr, taskId, user});          // remove old
        info[taskId].second = newPriority;
        pq.insert({newPriority, taskId, user});   // insert new
    }

    void rmv(int taskId) {
        auto [user, pr] = info[taskId];
        pq.erase({pr, taskId, user});
        info.erase(taskId);
    }

    int execTop() {
        if (pq.empty()) return -1;
        auto [pr, id, user] = *pq.begin(); // highest priority & taskId
        pq.erase(pq.begin());
        info.erase(id);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */