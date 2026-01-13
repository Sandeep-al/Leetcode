class Solution {
public:
    int m;
    int n;

    int move(int idx1, int idx2, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {

        if (idx2 < 0 || idx2 >= n) {
            return 1e9;
        }

        if (idx1 == m - 1) {
            return matrix[idx1][idx2];
        }

        if (dp[idx1][idx2] != -1e9) {
            return dp[idx1][idx2];
        }

        int left = move(idx1 + 1, idx2 - 1, matrix, dp);
        int down = move(idx1 + 1, idx2, matrix, dp);
        int right = move(idx1 + 1, idx2 + 1, matrix, dp);

        return dp[idx1][idx2] = matrix[idx1][idx2] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1e9));

        int ans = 1e9;

        for (int j = 0; j < n; j++) {
            ans = min(ans, move(0, j, matrix, dp));
        }

        return ans;
    }
};