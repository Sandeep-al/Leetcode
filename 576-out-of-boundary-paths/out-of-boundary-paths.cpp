class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>>dp;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int solve(int i, int j, int moves_left) {
        if (i >= m || i < 0 || j >= n || j < 0)
            return 1;
        if (moves_left == 0)
            return 0;

        if(dp[i][j][moves_left]!=-1) return dp[i][j][moves_left];
        long long  ans = 0;
        for (auto& it : directions) {
            int x_i = it[0] + i;
            int x_j = it[1] + j;

            ans = (ans +solve(x_i, x_j, moves_left - 1))%1000000007;
        }

        return dp[i][j][moves_left]=ans ;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m;
        this->n=n;
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove);
    }
};