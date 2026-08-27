class Solution {
public:
    vector<vector<int>> used;
    vector<vector<char>> board;
    string word;
    int m;
    int n;
    int n1;
    bool solve(int i, int j, int idx) {

        if (idx == n1) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || used[i][j] ||
            board[i][j] != word[idx]) {
            return false;
        }

        used[i][j] = true;

        bool ans = solve(i + 1, j, idx + 1) || solve(i - 1, j, idx + 1) ||
                   solve(i, j - 1, idx + 1) || solve(i, j + 1, idx + 1);

        used[i][j] = false;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        m = board.size();
        n = board[0].size();
        n1 = word.size();
        used.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (solve(i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};