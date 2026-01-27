class Solution {
public:
    int m;
    int n;
    vector<vector<int>> travel{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<int>>& board) {

        if (i < 0 || i >= m || j >= n || j < 0 || board[i][j] != 1) {
            return;
        }

        board[i][j] = -1;
        for (auto& it : travel) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            dfs(temp_i, temp_j, board);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || i == m - 1 || j == n - 1 || j == 0) {
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