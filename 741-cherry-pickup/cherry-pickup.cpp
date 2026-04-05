class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int n;
    
    int solve(int row1, int col1, int row2) {
        int col2 = row1 + col1 - row2;
        
        if (row1 >= n || col1 >= n || row2 >= n || col2 >= n || 
            grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return INT_MIN;
        }
        
        if (row1 == n - 1 && col1 == n - 1) {
            return grid[row1][col1];
        }
        
        if (dp[row1][col1][row2] != -1) {
            return dp[row1][col1][row2];
        }
        
        int cherry = 0;
        cherry += grid[row1][col1];
        
        if (row1 != row2 || col1 != col2) {
            cherry += grid[row2][col2];
        }
        
        int down_down = solve(row1 + 1, col1, row2 + 1);
        int down_right = solve(row1 + 1, col1, row2);
        int right_down = solve(row1, col1 + 1, row2 + 1);
        int right_right = solve(row1, col1 + 1, row2);
        
        int next = max({down_down, down_right, right_down, right_right});
        
        if (next == INT_MIN) {
            return dp[row1][col1][row2] = INT_MIN;
        }
        
        return dp[row1][col1][row2] = cherry + next;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        int ans = solve(0, 0, 0);
        
        return max(ans, 0);
    }
};