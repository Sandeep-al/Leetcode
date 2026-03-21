class Solution {
public:
    int m;
    int n;
    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<char>> grid;
    vector<vector<int>> vis;
    void solve(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 ||
            grid[i][j] == '0') {
            return;
        }

        vis[i][j] = 1;

        for (auto& it : directions) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            solve(temp_i, temp_j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        this->grid = grid;
        vis.assign(m, vector<int>(n, 0));
        int count=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j]==0) {
                    solve(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};