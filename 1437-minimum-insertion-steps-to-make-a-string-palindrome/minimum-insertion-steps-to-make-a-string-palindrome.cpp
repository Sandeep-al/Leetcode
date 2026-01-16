class Solution {
public:
    int move(string& s, vector<vector<int>>& dp, int idx1, int idx2) {
        if (idx1 >= idx2) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if (s[idx1] == s[idx2]) {
            return dp[idx1][idx2] = 0 + move(s, dp, idx1 + 1, idx2 - 1);
        }

        return  dp[idx1][idx2] =1+ min(move(s, dp, idx1 + 1, idx2),
                                        move(s, dp, idx1, idx2 - 1));
    }
    int minInsertions(string s) {

        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return move(s,dp,0,n-1);
    }
};