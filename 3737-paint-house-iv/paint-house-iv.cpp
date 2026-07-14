class Solution {
public:
    int n;
    vector<vector<int>>cost;
    long long dp[50005][4][4];
    long long solve(int idx, int prev1, int prev2) {

        if (idx == n/2)
            return 0;

        // u can paint with any colour if doent matches previous
        // and also doesnt matches the equidistant thats idx + x== n-1
        if(dp[idx][prev1+1][prev2+1]!=-1) return dp[idx][prev1+1][prev2+1];
        long long ans = LLONG_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j && prev1 != i && prev2 != j) {
                    ans = min(ans, 1LL * cost[idx][i] +
                                       1LL * cost[n - idx - 1][j] +
                                       1LL * solve(idx + 1, i, j));
                }
            }
        }

         return dp[idx][prev1+1][prev2+1]=ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        

        this->n=n;
        this->cost=cost;
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1);
    }
};