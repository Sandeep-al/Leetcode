class Solution {
public:
    int move(string&s, string&t,int idx1,int idx2,vector<vector<int>>&dp){

        if(idx2<0) return 1;
        if(idx1<0) return 0;

        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int pick=0;
        int notpick=0;
        if(s[idx1]==t[idx2])//matching i have two options
        {
            //pick
            pick=move(s,t,idx1-1,idx2-1,dp);
            notpick=move(s,t,idx1-1,idx2,dp);

            return dp[idx1][idx2]=pick+notpick;
        }


        return dp[idx1][idx2]=move(s,t,idx1-1,idx2,dp);
    }
    int numDistinct(string s, string t) {


        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return move(s,t,m-1,n-1,dp);
        
    }
};