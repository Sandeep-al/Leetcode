class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<int>>& grid) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 0;

        for (auto& it : directions) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            dfs(temp_i, temp_j, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 &&
                    (i == m - 1 || i == 0 || j == n - 1 || j == 0)) {
                    dfs(i, j, grid);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};