class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int compute(vector<vector<int>>& visited,
                vector<vector<int>>& grid,
                int i, int j, int remain) {

        if (i < 0 || i >= m || j < 0 || j >= n ||
            grid[i][j] == -1 || visited[i][j] == 1) {
            return 0;
        }

        
        remain--;

        if (grid[i][j] == 2) {
            return remain == 0;
        }

        visited[i][j] = 1;
        int sum = 0;

        for (int k = 0; k < 4; k++) {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];
            sum += compute(visited, grid, ni, nj, remain);
        }

        visited[i][j] = 0;
        return sum;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int si = 0, sj = 0;
        int remain = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    remain++;              // count 0,1,2
                }
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        return compute(visited, grid, si, sj, remain);
    }
};
