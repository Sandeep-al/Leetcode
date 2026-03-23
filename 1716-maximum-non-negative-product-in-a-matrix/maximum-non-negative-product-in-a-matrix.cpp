class Solution {
public:
    int m, n;
    long long mod = 1e9 + 7;
    vector<vector<int>> grid;

   
    vector<vector<pair<long long, long long>>> memo;
    vector<vector<bool>> vis;

    pair<long long, long long> solve(int i, int j) {

        
        if (i >= m || j >= n)
            return {LLONG_MIN, LLONG_MAX};

        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (vis[i][j]) return memo[i][j];

        auto right = solve(i, j + 1);
        auto down  = solve(i + 1, j);

        long long curr = grid[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        
        if (right.first != LLONG_MIN) {
            long long a = right.first * curr;
            long long b = right.second * curr;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        
        if (down.first != LLONG_MIN) {
            long long a = down.first * curr;
            long long b = down.second * curr;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        vis[i][j] = true;
        return memo[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& gridInput) {
        grid = gridInput;
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<pair<long long, long long>>(n));
        vis.assign(m, vector<bool>(n, false));

        auto res = solve(0, 0);

        if (res.first < 0) return -1;

        return res.first % mod;  
    }
};