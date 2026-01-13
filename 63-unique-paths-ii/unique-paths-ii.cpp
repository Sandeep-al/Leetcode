class Solution {
public:
    int M, N;

    int move(int idx1, int idx2, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid) {

        if (idx1 < 0 || idx1 >= M || idx2 < 0 || idx2 >= N ||obstacleGrid[idx1][idx2]==1) {
            return 0;
        }
        if (idx1 == 0 && idx2 == 0) {
            return 1;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int left = move(idx1, idx2 - 1, dp,obstacleGrid);
        int up = move(idx1 - 1, idx2, dp,obstacleGrid);

        return dp[idx1][idx2] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        M=m;
        N=n;

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return move(m-1,n-1,dp,obstacleGrid);


    }
};