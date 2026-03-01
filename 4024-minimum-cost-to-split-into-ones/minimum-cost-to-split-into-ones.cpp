class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 1) {
            return 0;
        }
        if (dp[n] != -1)
            return dp[n];
        int mini = INT_MAX;
        for (int i = 1; i <= n / 2; i++) {
            mini = min(mini, (i * (n - i)) + solve(n - i) + solve(i));
        }

        return dp[n] = mini;
    }
    // int minCost(int n) {
    //     dp.assign(n + 1, -1);
    //     return solve(n);
    // }
    // int minCost(int n) {
    //     vector<int> dp;
    //     dp.assign(n + 1, -1);
    //     dp[1] = 0;
    //     for (int x = 2; x <= n; x++) {
    //         int mini = INT_MAX;
    //         for (int i = 1; i <= x/2; i++) {
    //             mini = min(mini, (i * (x - i)) + dp[x - i] + dp[i]);
    //             dp[x]=mini;
    //         }
    //     }

    //     return dp[n];
    // }

    int minCost(int n) { return n * (n - 1) / 2; }
};