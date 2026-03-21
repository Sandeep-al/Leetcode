class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<char>> gride;

    void solve(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || gride[i][j] == '0') {
            return;
        }

        gride[i][j] = '0';

        for (auto& it : directions) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            solve(temp_i, temp_j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        this->gride = grid;
       
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gride[i][j] == '1') {
                    solve(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};