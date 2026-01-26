class Solution {
public:
    int function(int i, int j, vector<int>& values, vector<vector<int>>&dp) {
        if (i == j-1)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for (int x = i + 1; x < j; x++) {
            int curr_cost = values[i] * values[j] * values[x];
            mini = min(mini, curr_cost + function(i, x,values,dp) + function(x, j,values,dp));
        }

        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return function(0,n-1,values,dp);
    }
};