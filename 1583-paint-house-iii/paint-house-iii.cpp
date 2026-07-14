class Solution {
public:
    int m;
    int n;
    vector<int> houses;
    vector<vector<int>> cost;
    int dp[105][25][105];

    int solve(int idx, int prev, int k) {
        if (k < 0)
            return INT_MAX;
        if (idx == m) {
            return (k == 0) ? 0 : INT_MAX;
        }

        if (dp[idx][prev + 1][k] != -1) {
            return dp[idx][prev + 1][k];
        }

        int mini = INT_MAX;
        if (houses[idx] == 0) {
            for (int i = 1; i <= n; i++) {
                if (i == prev) {
                    int ans = solve(idx + 1, i, k);
                    if (ans != INT_MAX) {
                        ans += cost[idx][i - 1];
                    }
                    mini = min(mini, ans);
                } else {
                    int ans = solve(idx + 1, i, k - 1);
                    if (ans != INT_MAX) {
                        ans += cost[idx][i - 1];
                    }
                    mini = min(mini, ans);
                }
            }
        } else {
            if (houses[idx] == prev) {
                int ans = solve(idx + 1, houses[idx], k);
                mini = min(mini, ans);
            } else {
                int ans = solve(idx + 1, houses[idx], k - 1);
                mini = min(mini, ans);
            }
        }

        return dp[idx][prev + 1][k] = mini;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m = m;
        this->n = n;
        this->houses = houses;
        this->cost = cost;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, -1, target);
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};