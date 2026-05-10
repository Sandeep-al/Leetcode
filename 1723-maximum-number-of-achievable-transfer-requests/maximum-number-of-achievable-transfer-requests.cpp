class Solution {
public:
    vector<vector<int>> requests;
    int n;
    int x;
    vector<int> state;
    int maxi = 0;
    int solve(int idx) {

        if (idx == x) {
            int all_zero = 1;
            for (int i = 0; i < n; i++) {
                if (state[i] != 0) {
                    all_zero = 0;
                }
            }

            if (all_zero)
                return 0;

            return INT_MIN;
        }

        int maxi = INT_MIN;

        // take it

        state[requests[idx][0]]--;
        state[requests[idx][1]]++;

        int ans = solve(idx + 1);

        if (ans != INT_MIN) {
            maxi = max(maxi, 1 + ans);
        }

        // dont take it

        state[requests[idx][0]]++;
        state[requests[idx][1]]--;

        ans = solve(idx + 1);
        maxi = max(maxi, ans);

        return maxi;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        x = requests.size();
        this->n = n;
        this->requests = requests;
        state.assign(n, 0);

        return solve(0);
    }
};