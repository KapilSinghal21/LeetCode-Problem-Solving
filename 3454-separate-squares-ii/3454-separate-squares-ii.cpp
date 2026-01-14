class Solution {
public:
    using ll = long long;

    struct Event {
        ll y;
        ll x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    ll unionLength(vector<pair<ll,ll>>& v) {
        if (v.empty()) return 0;
        sort(v.begin(), v.end());
        ll res = 0, l = v[0].first, r = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > r) {
                res += r - l;
                l = v[i].first;
                r = v[i].second;
            } else {
                r = max(r, v[i].second);
            }
        }
        res += r - l;
        return res;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        for (auto &s : squares) {
            ll x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end());

        vector<pair<ll,ll>> active;
        long double totalArea = 0;
        vector<tuple<ll,ll,ll>> strips;

        for (int i = 0; i + 1 < events.size(); i++) {
            if (events[i].type == 1)
                active.push_back({events[i].x1, events[i].x2});
            else {
                auto it = find(active.begin(), active.end(),
                               make_pair(events[i].x1, events[i].x2));
                if (it != active.end()) active.erase(it);
            }

            ll dy = events[i + 1].y - events[i].y;
            if (dy == 0) continue;

            ll width = unionLength(active);
            if (width > 0) {
                totalArea += (long double)dy * width;
                strips.push_back({events[i].y, events[i + 1].y, width});
            }
        }

        long double half = totalArea / 2.0;
        long double curr = 0;

        for (auto &[y1, y2, w] : strips) {
            long double area = (long double)(y2 - y1) * w;
            if (curr + area >= half) {
                return (double)(y1 + (half - curr) / w);
            }
            curr += area;
        }
        return 0.0;
    }
};
