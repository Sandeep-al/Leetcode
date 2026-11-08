class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        for (int x = 0; x < m; x++) {

            if (grid[x][j] == 1 && x!=i) {
                count++;
            }
        }

        for (int x = 0; x < n; x++) {

            if (grid[i][x] == 1 && x!=j) {
                count++;
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j]) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    if (count) {
                        total++;
                    }
                }
            }
        }

        return total;
    }
};