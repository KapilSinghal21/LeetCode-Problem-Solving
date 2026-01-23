using ll = long long;

class Solution {
public:
    int minimumPairRemoval(vector<int>& a) {
        vector<int> left;
        vector<int> right;
        vector<ll> nums; 
        int n = a.size();

        for(auto v: a) nums.push_back(v);
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>> q;
        for (int i = 0; i <= n; i++) {
            left.push_back(i - 1);
            right.push_back(i + 1);
        }

        int bad = 0;
        int ans = 0;

        for (int i = 1; i < n; i++) {
            q.push(make_pair(nums[i] + nums[i - 1], i));
            bad += (nums[i] < nums[i - 1]);
        }

        while (bad != 0) {
            auto v = q.top();
            q.pop();
            ll sum = v.first;
            int r = v.second;

            int l = left[r];
            if (l == -1 || nums[l] + nums[r] != sum) continue;

            if (nums[l] > nums[r]) bad -= 1;
            
            right[l] = right[r];
            left[right[r]] = l;

            int rr = right[r];
            int ll1 = left[l];

            if (ll1 != -1) {
                bad += (nums[ll1] > sum) - (nums[ll1] > nums[l]);
                q.push(make_pair(nums[ll1] + sum, l));
            }

            if (rr < n) {
                bad += (nums[rr] < sum) - (nums[rr] < nums[r]);
                q.push(make_pair(nums[rr] + sum, rr));
            }
            
            nums[l] = sum;
            nums[r] = 1e5;
            ans += 1;
        }
        return ans;
    }
};