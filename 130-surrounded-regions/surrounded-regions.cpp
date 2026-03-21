class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;
    void dfs(int i, int j, vector<vector<char>>& board) {

        if (!(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')) {
            return;
        }

        board[i][j] = '#';

        for (auto& jt : directions) {
            int temp_i = i + jt[0];
            int temp_j = j + jt[1];

            dfs(temp_i, temp_j,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' &&
                    (i == m - 1 || j == n - 1 || i == 0 || j == 0)) {
                    dfs(i, j,board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j<n; j++) {
                if (board[i][j] != '#') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};