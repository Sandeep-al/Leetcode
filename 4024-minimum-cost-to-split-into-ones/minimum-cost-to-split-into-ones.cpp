class Solution {
public:
    vector<int>dp;
    int solve(int n){
        if(n==1){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int mini=INT_MAX;
        for(int i=1;i<=n/2;i++){
            mini=min(mini,(i*(n-i))+solve(n-i)+solve(i));
        }

        return dp[n]=mini;
    }
    int minCost(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};