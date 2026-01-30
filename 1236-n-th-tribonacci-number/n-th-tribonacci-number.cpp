class Solution {
public:

    int find(int x,vector<int>&dp){
        if(x==0||x==1) return x;
        if(x==2) return 1;

        if(dp[x]!=-1) return dp[x];

        return dp[x]=find(x-1,dp)+find(x-2,dp)+find(x-3,dp);
    }
    
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return find(n,dp);
        
    }
};