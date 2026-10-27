class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int m;
    int n;
    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<int>>& vis, int& count1, int& count2) {

        vis[i][j] = 1;
        
        if (i == m - 1 || j == n-1) {
            count1++;
        }

        if (i == 0 || j == 0) {
            count2++;
        }

        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];

            if (ii >= 0 && ii <= m - 1 && jj >= 0 && jj <= n - 1 &&
                !vis[ii][jj] && heights[ii][jj] <= heights[i][j]) {
                dfs(heights, ii, jj, vis, count1, count2);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> vis;
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count1 = 0;
                int count2 = 0;
                vis.assign(m, vector<int>(n, 0));
                dfs(heights, i, j, vis, count1, count2);
                if (count1 && count2) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};