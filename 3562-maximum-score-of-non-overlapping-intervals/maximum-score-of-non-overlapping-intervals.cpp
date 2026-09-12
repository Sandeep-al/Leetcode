class Solution {
public:
    int n;

    struct State {
        long long weight = 0;
        array<int, 4> indices{};
        int len = 0;
    };

    int bs(int curr_idx, vector<vector<int>>& intervals) {

        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (intervals[mid][0] > intervals[curr_idx][1]) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool better(const State& a, const State& b) {

        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }

        int len = min(a.len, b.len);

        for (int i = 0; i < len; i++) {

            if (a.indices[i] != b.indices[i]) {
                return a.indices[i] < b.indices[i];
            }
        }

        return a.len < b.len;
    }

    State solve(int idx, int count,
                vector<vector<int>>& intervals,
                vector<vector<State>>& dp,
                vector<vector<bool>>& vis,
                vector<int>& nxt) {

        if (count == 4 || idx == n) {
            return State();
        }

        if (vis[idx][count]) {
            return dp[idx][count];
        }

        vis[idx][count] = true;

        int to_jump = nxt[idx];

       
        State take = solve(to_jump, count + 1,
                           intervals, dp, vis, nxt);

        take.weight += intervals[idx][2];

        take.indices[take.len++] = intervals[idx][3];

       
        sort(take.indices.begin(),
             take.indices.begin() + take.len);

        
        State not_take = solve(idx + 1, count,
                               intervals, dp, vis, nxt);

        if (better(take, not_take)) {
            dp[idx][count] = take;
        }
        else {
            dp[idx][count] = not_take;
        }

        return dp[idx][count];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

    
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = bs(i, intervals);
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));
        vector<vector<bool>> vis(n + 1, vector<bool>(5, false));

        State ans = solve(0, 0, intervals, dp, vis, nxt);

        vector<int> result;

        for (int i = 0; i < ans.len; i++) {
            result.push_back(ans.indices[i]);
        }

        return result;
    }
};