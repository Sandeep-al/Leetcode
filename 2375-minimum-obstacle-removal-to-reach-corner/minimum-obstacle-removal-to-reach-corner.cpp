class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        deque<pair<int, pair<int, int>>> dq;

        dq.push_front({0, {0, 0}});
        dis[0][0] = 0;

        while (!dq.empty()) {
            auto node = dq.front();
            dq.pop_front();

            int obs = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x == m - 1 && y == n - 1) {
                return obs;
            }

            for (auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int current_cost = grid[nx][ny];
                    int new_obs = obs + current_cost;

                    if (new_obs < dis[nx][ny]) {
                        dis[nx][ny] = new_obs;

                        if (current_cost == 0) {
                            dq.push_front({new_obs, {nx, ny}});
                        } else {
                            dq.push_back({new_obs, {nx, ny}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};