class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<vector<int>>> dp;
    int m;
    int n;
    bool solve(int i, int j, int score) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if(dp[i][j][score]!=-1) return dp[i][j][score];
        char curr = grid[i][j];
        if (i == m - 1 && j == n - 1) {
            int curr_score = 0;
            if (curr == '(')
                curr_score += 1;
            if (curr == ')')
                curr_score -= 1;

            if ((score + curr_score) == 0)
                return dp[i][j][score]=true;

            return dp[i][j][score]=false;
        }

        if (score == 0 && curr == ')')
            return dp[i][j][score]=false;
        int curr_score = 0;
        if (curr == '(')
            curr_score += 1;
        if (curr == ')')
            curr_score -= 1;
        int call1 = solve(i + 1, j, score + curr_score);
        int call2 = solve(i, j + 1, score + curr_score);

        return dp[i][j][score]= call1 || call2;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));
        return solve(0, 0, 0);
    }
};