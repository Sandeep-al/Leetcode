class Solution {
public:
    int n;
    int move(vector<vector<int>>& triangle,int idx1,int idx2,vector<vector<int>>&dp){
        

        if(idx1==n-1){
            return triangle[idx1][idx2];
        }
        if(dp[idx1][idx2]!=-1e9){
            return dp[idx1][idx2];
        }
        //going down

        int down=move(triangle,idx1+1,idx2,dp);
        int downright=move(triangle,idx1+1,idx2+1,dp);

        return dp[idx1][idx2]=triangle[idx1][idx2]+min(down,downright);


    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1e9));

        return move(triangle,0,0,dp);

    }
};