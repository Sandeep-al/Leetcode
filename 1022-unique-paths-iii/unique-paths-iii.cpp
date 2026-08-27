class Solution {
public:
    int m;
    int n;
    vector<vector<int>> vis;
    vector<vector<int>> grid;
    int solve(int i, int j, int remaining) {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] ||
            grid[i][j] == -1) {
            return 0;
        }
        if (grid[i][j] == 2) {
            return remaining == -1;
        }
        vis[i][j] = 1;
        int ans = 0;
        ans += solve(i + 1, j, remaining - 1);
        ans += solve(i, j + 1, remaining - 1);
        ans += solve(i - 1, j, remaining - 1);
        ans += solve(i, j - 1, remaining - 1);
        vis[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));
        this->grid = grid;
        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += (grid[i][j] == 0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return solve(i, j, total);
                }
            }
        }

        return 0;
    }
};