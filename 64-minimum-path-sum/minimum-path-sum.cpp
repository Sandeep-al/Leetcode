class Solution {
public:
    int M, N;

    int move(int idx1, int idx2, vector<vector<int>>& dp,
             vector<vector<int>>& obstacleGrid) {

        if (idx1 < 0 || idx1 >= M || idx2 < 0 || idx2 >= N) {
            return 1000000;
        }
        if (idx1 == 0 && idx2 == 0) {
            return obstacleGrid[0][0];
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int left =
            obstacleGrid[idx1][idx2] + move(idx1, idx2 - 1, dp, obstacleGrid);
        int up =
            obstacleGrid[idx1][idx2] + move(idx1 - 1, idx2, dp, obstacleGrid);

        return dp[idx1][idx2] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));

        return move(M - 1, N - 1, dp, grid);
    }
};