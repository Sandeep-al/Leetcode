class Solution {
public:
    int m;
    int n;
    vector<int>dx={0,0,-1,1};
    vector<int>dy={1,-1,0,0};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,
             long long& sum) {

        vis[i][j] = 1;
        sum += grid[i][j];

        for (int x = 0; x < 4; x++) {
            int ii = i + dx[x];
            int jj = j + dy[x];

            if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] != 0 &&
                !vis[ii][jj]) {
                dfs(grid, vis, ii, jj, sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]!=0 && !vis[i][j]) {
                    long long curr = 0;
                    dfs(grid, vis, i, j, curr);
                    if ((curr % k) == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};