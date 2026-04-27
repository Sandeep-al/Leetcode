class Solution {
public:
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, 1}, {0, -1}}},
        {2, {{1, 0}, {-1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{0, 1}, {-1, 0}}}
    };

    vector<vector<int>> grid, vis;
    int m, n;

    bool solve(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j])
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        vis[i][j] = 1;

        for (auto& it : directions[grid[i][j]]) {
            int dx = it[0];
            int dy = it[1];

            int idx = i + dx;
            int idy = j + dy;

            if (idx < 0 || idy < 0 || idx >= m || idy >= n)
                continue;

            
            bool ok = false;
            for (auto& nxt : directions[grid[idx][idy]]) {
                if (nxt[0] == -dx && nxt[1] == -dy) {
                    ok = true;
                    break;
                }
            }

            if (ok && solve(idx, idy))
                return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));

        return solve(0, 0);
    }
};