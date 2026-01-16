class Solution {
public:
    int m;
    int n;
    int move(string& word1, string& word2, int idx1, int idx2,vector<vector<int>>&dp) {

        if (idx1 == m) {
            return n - idx2;
        }

        if (idx2 == n) {
            return m - idx1;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if (word1[idx1] == word2[idx2]) {
            return move(word1, word2, idx1 + 1, idx2 + 1,dp);
        }

        return dp[idx1][idx2]= 1 + min(move(word1, word2, idx1 + 1, idx2,dp),
                       move(word1, word2, idx1, idx2 + 1,dp));
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return move(word1, word2, 0, 0,dp);
    }
};