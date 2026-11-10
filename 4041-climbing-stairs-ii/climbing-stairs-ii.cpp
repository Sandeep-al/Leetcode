class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int idx, vector<int>& costs) {

        if (idx == n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        // jump
        int cost = INT_MAX;
        if (idx + 1 <= n) {
            cost = min(cost, costs[idx] + 1 + solve(idx + 1, costs));
        }

        if (idx + 2 <= n) {
            cost = min(cost, costs[idx + 1] + 4 + solve(idx + 2, costs));
        }

        if (idx + 3 <= n) {
            cost = min(cost, costs[idx + 2] + 9 + solve(idx + 3, costs));
        }

        return dp[idx] = cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        this->n = n;
        dp.assign(n + 1, -1);
        return solve(0, costs);
    }
};