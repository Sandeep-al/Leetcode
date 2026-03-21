class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        int no_of_fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    no_of_fresh++;
                }
            }
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int curr_time = it.second;

            for (auto& jt : directions) {
                int temp_x = x + jt[0];
                int temp_y = y + jt[1];

                if (temp_x >= 0 && temp_x < m && temp_y >= 0 && temp_y < n &&
                    grid[temp_x][temp_y] == 1) {
                    q.push({{temp_x, temp_y}, curr_time + 1});
                    grid[temp_x][temp_y] = 2;
                }
            }

            time = max(time, curr_time);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};