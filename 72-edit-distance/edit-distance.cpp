class Solution {
public:
    int move(string& word1, string& word2, int idx1, int idx2,
             vector<vector<int>>& dp) {

        if (idx1 < 0)
            return idx2 + 1;
        if (idx2 < 0)
            return idx1 + 1;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (word1[idx1] == word2[idx2]) {
            return dp[idx1][idx2] = move(word1, word2, idx1 - 1, idx2 - 1, dp);
        }

        int insertOp = move(word1, word2, idx1, idx2 - 1, dp);
        int deleteOp = move(word1, word2, idx1 - 1, idx2, dp);
        int replaceOp = move(word1, word2, idx1 - 1, idx2 - 1, dp);

        return dp[idx1][idx2] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return move(word1, word2, m - 1, n - 1, dp);
    }
};