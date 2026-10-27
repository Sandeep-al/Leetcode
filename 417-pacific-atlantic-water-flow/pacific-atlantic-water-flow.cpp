class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int m;
    int n;
    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<int>>& vis) {

        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];

            if (ii >= 0 && ii <= m - 1 && jj >= 0 && jj <= n - 1 &&
                !vis[ii][jj] && heights[ii][jj] >= heights[i][j]) {
                dfs(heights, ii, jj, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
         m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> vis1(m, vector<int>(n, 0));
        vector<vector<int>> vis2(m, vector<int>(n, 0));
       
        vector<vector<int>> ans;

        // pacific ocean
        for (int i = 0; i < m; i++) {
            if (!vis1[i][0]) {
                dfs(heights, i, 0, vis1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis1[0][i]) {
                dfs(heights, 0, i, vis1);
            }
        }

        // atlantic

        for (int i = 0; i < m; i++) {
            if (!vis2[i][n - 1]) {
                dfs(heights, i, n - 1, vis2);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis2[m - 1][i]) {
                dfs(heights, m - 1, i, vis2);
            }
        }

        // check
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};