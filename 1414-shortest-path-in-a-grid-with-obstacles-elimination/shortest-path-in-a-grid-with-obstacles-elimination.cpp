class Solution {
public:
    int m, n;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
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

        for (auto& dir : directions) {
            dfs(grid, x + dir.first, y + dir.second, k, steps + 1);
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // if (k >= m + n - 2)
        //     return m + n - 2;

        // for (int i = 0; i < 41; i++) {
        //     for (int j = 0; j < 41; j++) {
        //         for (int l = 0; l < 1605; l++) {
        //             memo[i][j][l] = INT_MAX;
        //         }
        //     }
        // }

        // dfs(grid, 0, 0, k, 0);

        // return min_ans == INT_MAX ? -1 : min_ans;

        queue<pair<int, pair<int, int>>> q;

        // {remaining_k, {x,y}}
        q.push({k, {0, 0}});

        vector<vector<vector<int>>> dis(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        dis[0][0][k] = 0;

        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int curr_k = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x == m - 1 && y == n - 1)
                return dis[x][y][curr_k];

            for (auto& dir : directions) {

                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int nk = curr_k - grid[nx][ny];

                if (nk < 0)
                    continue;

                if (dis[nx][ny][nk] == -1) {

                    dis[nx][ny][nk] = dis[x][y][curr_k] + 1;

                    q.push({nk, {nx, ny}});
                }
            }
        }

        return -1;
    }
};