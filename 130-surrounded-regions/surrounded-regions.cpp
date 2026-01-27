class Solution {
public:
    int m;
    int n;
    vector<vector<int>> travel{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<char>>& board) {

        if (i < 0 || i >= m || j >= n || j < 0 || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';
        for (auto& it : travel) {
            int temp_i = i + it[0];
            int temp_j = j + it[1];

            dfs(temp_i, temp_j, board);
        }
    }
    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 || i == m - 1 || j == n - 1 || j == 0) {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};