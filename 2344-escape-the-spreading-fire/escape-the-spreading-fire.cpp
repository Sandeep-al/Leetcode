class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool can_we_travel(int wait_time, vector<vector<int>>& grid) {
        if (grid[0][0] <= wait_time) return false;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        q.push({wait_time, {0, 0}});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int curr_time = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] != -1) {
                    if (nx == m - 1 && ny == n - 1) {
                        if (grid[nx][ny] >= curr_time + 1) {
                            return true; 
                        }
                    } 
                    else if (grid[nx][ny] > curr_time + 1) {
                        vis[nx][ny] = 1;
                        q.push({curr_time + 1, {nx, ny}});
                    }
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = -1;
                }
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int curr_time = it.first;
            int x = it.second.first;
            int y = it.second.second;

            grid[x][y] = curr_time;

            for (auto& jt : directions) {
                int temp_i = x + jt[0];
                int temp_j = y + jt[1];

                if (temp_i >= 0 && temp_i < m && temp_j >= 0 && temp_j < n &&
                    vis[temp_i][temp_j] == 0 && grid[temp_i][temp_j] == 0) {
                    
                    vis[temp_i][temp_j] = 1;
                    q.push({curr_time + 1, {temp_i, temp_j}});
                }
            }
        }

        int INF = 2e9;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    grid[i][j] = INF;
                }
            }
        }

        int low = 0;
        int high = 1e9;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can_we_travel(mid, grid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(ans>1e9) return 1e9;
        return ans;
    }
};