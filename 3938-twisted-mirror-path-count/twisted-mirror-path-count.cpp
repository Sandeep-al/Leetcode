class Solution {
public:
    // remember from which direction ur coming
    // which cell ur right now thats it
    // dir==0 u came from left /// dir==1 u came from top
    int mod = 1e9 + 7;

    vector<vector<vector<int>>> dp;
    int m;
    int n;
    int solve(int i, int j, int dir, vector<vector<int>>& grid) {

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j][dir] != -1) {
            return dp[i][j][dir];
        }
        int ans = 0;
        if (grid[i][j] == 1) {
            if (dir == 1) {
                ans = (ans + solve(i, j + 1, 0, grid)) % mod;
            } else if (dir == 0) {
                ans = (ans + solve(i + 1, j, 1, grid)) % mod;
            }
        } else {
            ans = (ans + solve(i + 1, j, 1, grid)) % mod;
            ans = (ans + solve(i, j + 1, 0, grid)) % mod;
        }

        return dp[i][j][dir] = ans % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return solve(0, 0, 0, grid);
    }
};