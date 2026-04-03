class Solution {
public:
    vector<vector<vector<int>>> dp;

    int helper(int i,int j,int left,vector<vector<int>>& coins){
        if(i==coins.size()||j==coins[0].size()) return -1e9;

        if(dp[i][j][left]!=INT_MAX) return dp[i][j][left];

        if(i==coins.size()-1&&j==coins[0].size()-1){
            int val=coins[i][j];
            if(val<0&&left>0) return dp[i][j][left]=0;
            return dp[i][j][left]=val;
        }

        int curr=coins[i][j];

        int down=helper(i+1,j,left,coins);
        int right=helper(i,j+1,left,coins);

        int res=-1e9;
        int ans=max(down,right);
        if(ans!=-1e9){
            res=ans+curr;
        }

        if(curr<0&&left>0){
            int down2=helper(i+1,j,left-1,coins);
            int right2=helper(i,j+1,left-1,coins);
            int neutralized=max(down2,right2);
            
            res=max(res,neutralized);
        }

        return dp[i][j][left]=res;
    }

    int maximumAmount(vector<vector<int>>& coins){
        int n=coins.size(),m=coins[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MAX)));
        return helper(0,0,2,coins);
    }
};