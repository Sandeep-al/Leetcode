class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int min_ans = INT_MAX;

    int memo[41][41][1605];

    void dfs(vector<vector<int>>& grid, int x, int y, int k, int steps) {

        if (x < 0 || x >= m || y < 0 || y >= n)
            return;

        if (grid[x][y] == 1) {
            if (k == 0)
                return;
            k--;
        }

        if (steps >= min_ans)
            return;

        if (x == m - 1 && y == n - 1) {
            min_ans = min(min_ans, steps);
            return;
        }

        if (memo[x][y][k] <= steps)
            return;

        memo[x][y][k] = steps;

        for (auto& dir : dirs) {
            dfs(grid, x + dir.first, y + dir.second, k, steps + 1);
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        if (k >= m + n - 2)
            return m + n - 2;

        for (int i = 0; i < 41; i++) {
            for (int j = 0; j < 41; j++) {
                for (int l = 0; l < 1605; l++) {
                    memo[i][j][l] = INT_MAX;
                }
            }
        }

        dfs(grid, 0, 0, k, 0);

        return min_ans == INT_MAX ? -1 : min_ans;
    }
};