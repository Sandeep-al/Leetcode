class Solution {
public:
    vector<vector<int>> triangle;
    vector<vector<int>> dp;
    vector<vector<bool>> vis;

    int n;

    int solve(int row, int col) {

        if (row == n - 1)
            return triangle[row][col];

        if (vis[row][col])
            return dp[row][col];

        vis[row][col] = true;

        return dp[row][col] =
                   triangle[row][col] +
                   min(solve(row + 1, col),
                       solve(row + 1, col + 1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();

        this->triangle = triangle;

        dp.assign(n, vector<int>(n, 0));
        vis.assign(n, vector<bool>(n, false));

        return solve(0, 0);
    }
};