class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int m;
    int n;
    void check(vector<vector<int>>& vis, vector<vector<int>>& grid, int& valid,
               int i, int j) {

        vis[i][j] = 1;
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
            if (grid[i][j] == 0) {

                valid = 0;
            }
        }

        for (int x = 0; x < 4; x++) {
            int ii = i + dx[x];
            int jj = j + dy[x];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == 0 &&
                !vis[ii][jj]) {
                check(vis, grid, valid, ii, jj);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    int valid = 1;
                    check(vis, grid, valid, i, j);
                    if (valid) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};