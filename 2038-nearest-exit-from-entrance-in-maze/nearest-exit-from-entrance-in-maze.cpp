class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        int dist = -1;

        while (!q.empty()) {

            dist++;
            auto [dist, z] = q.front();
            q.pop();
            int x = z.first;
            int y = z.second;

            if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
                !(x == entrance[0] && y == entrance[1])) {
                return dist;
            }

            for (int k = 0; k < 4; k++) {
                int ii = x + dx[k];
                int jj = y + dy[k];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n &&
                    maze[ii][jj] == '.' && !vis[ii][jj]) {
                    vis[ii][jj] = 1;
                    q.push({dist + 1, {ii, jj}});
                }
            }
        }

        return -1;
    }
};