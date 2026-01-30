class Solution {
public:
    int rows, cols;
    int memo[301][301];

    int solve(int i, int j, vector<vector<char>>& matrix) {

        if (i < 0 || j < 0)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (matrix[i][j] == '0') {
            return memo[i][j] = 0;
        }

        int up = solve(i - 1, j, matrix);
        int left = solve(i, j - 1, matrix);
        int diag = solve(i - 1, j - 1, matrix);

        return memo[i][j] = 1 + min({up, left, diag});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        memset(memo, -1, sizeof(memo));

        int maxSide = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    maxSide = max(maxSide, solve(i, j, matrix));
                }
            }
        }

        return maxSide * maxSide;
    }
};