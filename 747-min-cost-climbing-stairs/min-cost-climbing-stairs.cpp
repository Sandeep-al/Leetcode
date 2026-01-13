class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1); 
        return solve(cost, n, dp);
    }

    int solve(vector<int>& cost, int i, vector<int>& dp) {
        
        if (i == 0) return cost[0];
        if (i == 1) return cost[1];

        if (dp[i] != -1) return dp[i];

        
        int currentStepCost = (i == cost.size()) ? 0 : cost[i];

        return dp[i] = currentStepCost + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));
    }
};