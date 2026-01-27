class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> final_ans(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int time = it.second;

            final_ans[i][j] = time;

            for (auto& jt : directions) {
                int nrow = i + jt[0];
                int ncol = j + jt[1];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1) {

                    grid[nrow][ncol] = 2;

                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        return final_ans;
    }
};