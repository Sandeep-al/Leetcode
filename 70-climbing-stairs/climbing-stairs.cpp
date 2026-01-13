class Solution {
public:
    int climbStairs(int n) {

        vector<int>dp(n+1,-1);
        return m(n,dp);

    }

    int m(int n,vector<int>&dp){
        if (n == 2 || n == 1) {
            return n;
        }
        if(dp[n]!=-1) return dp[n];

        return dp[n]=m(n - 1,dp) + m(n - 2,dp);
    }
};