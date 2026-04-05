class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int n;

    int solve(int i1, int j1, int k) {

        int j2 = i1 + j1 - k;

        if (i1 >= n || j1 >= n || k >= n || j2 >= n || grid[i1][j1] == -1 ||
            grid[k][j2] == -1) {
            return INT_MIN;
        }

        if (i1 == n - 1 && j1 == n - 1) {
            return grid[i1][j1];
        }

        if (dp[i1][j1][k] != -1) {
            return dp[i1][j1][k];
        }

        int cherry = 0;
        cherry += grid[i1][j1];

        if (i1 != k || j1 != j2) {
            cherry += grid[k][j2];
        }

        int down_down = solve(i1 + 1, j1, k + 1);
        int down_right = solve(i1 + 1, j1, k);
        int right_down = solve(i1, j1 + 1, k + 1);
        int right_right = solve(i1, j1 + 1, k);

        int next = max({down_down, down_right, right_down, right_right});

        if (next == INT_MIN) {
            return dp[i1][j1][k] = INT_MIN;
        }

        return dp[i1][j1][k] = cherry + next;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();

        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = solve(0, 0, 0);

        return max(ans, 0);
    }
};