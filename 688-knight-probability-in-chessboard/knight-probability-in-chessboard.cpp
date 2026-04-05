class Solution {
public:
    int m;
    
    vector<vector<vector<double>>> dp;
    vector<vector<int>> directions = {
        {-2, 1}, {-2, -1}, {2, 1}, {2, -1},
        {1, -2}, {-1, -2}, {1, 2}, {-1, 2}
    };

    double solve(int i, int j, int moves_left) {
        if (i >= m || i < 0 || j >= m || j < 0)
            return 0.0;

        if (moves_left == 0)
            return 1.0;

        if (dp[i][j][moves_left] != -1.0)
            return dp[i][j][moves_left];

        double ans = 0.0;

        for (auto& it : directions) {
            int x_i = it[0] + i;
            int x_j = it[1] + j;

            ans += solve(x_i, x_j, moves_left - 1) / 8.0;
        }

        return dp[i][j][moves_left] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        m = n;
        dp.assign(m, vector<vector<double>>(m, vector<double>(k + 1, -1.0)));
        return solve(row, column, k);
    }
};