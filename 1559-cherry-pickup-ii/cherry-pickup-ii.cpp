class Solution {
public:
    int m;
    int n;

    int move(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
             int idx1, int idx2, int idx3) {

        
        if (idx2 < 0 || idx3 < 0 || idx2 >= n || idx3 >= n) {
            return -1e8; 
        }

       
        if (idx1 == m - 1) {
            if (idx2 == idx3) {
                return grid[idx1][idx2];
            }
            return grid[idx1][idx2] + grid[idx1][idx3];
        }

        if (dp[idx1][idx2][idx3] != -1) {
            return dp[idx1][idx2][idx3];
        }

        
        int total = 0;
        if (idx2 == idx3) {
            total = grid[idx1][idx2];
        } else {
            total = grid[idx1][idx2] + grid[idx1][idx3];
        }

        
        int maxi = -1e8;
        
        
        for (int di = -1; di <= 1; di++) {
            
            for (int dj = -1; dj <= 1; dj++) {
                
                int ans = move(grid, dp, idx1 + 1, idx2 + di, idx3 + dj);
                maxi = max(maxi, ans);
            }
        }

        return dp[idx1][idx2][idx3] = total + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));

        
        return move(grid, dp, 0, 0, n - 1);
    }
};