class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    matrix[i][j] = 0;
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first.first;
            int y = it.first.second;
            int curr_distance = it.second;

            for (auto& jt : directions) {
                int temp_x = x + jt[0];
                int temp_y = y + jt[1];

                if (temp_x >= 0 && temp_x < m && temp_y >= 0 && temp_y < n &&
                    matrix[temp_x][temp_y] == -1) {
                    q.push({{temp_x, temp_y}, curr_distance + 1});
                    matrix[temp_x][temp_y] = curr_distance + 1;
                }
            }
        }

        return matrix;
    }
};