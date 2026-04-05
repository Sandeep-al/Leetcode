class Solution {
public:
    vector<vector<int>> grid;
    int m;
    int n;
    int k;
    vector<vector<vector<int>>>dp;
    int solve(int i, int j, int ans) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            int val = grid[i][j] % k;
            if ((val + ans) % k == 0)
                return 1;
            return 0;
        }

        if(dp[i][j][ans]!=-1) return dp[i][j][ans];

        int val = grid[i][j] % k;
        val = (val + ans) % k;

        int mod = 1e9 + 7;
        return dp[i][j][ans]=(solve(i+1,j,val) + solve(i,j+1,val)) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        this->grid = grid;
        this->k = k;
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(0, 0, 0);
    }
};