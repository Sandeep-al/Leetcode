class Solution {
public:
    vector<vector<char>> board;
    
    bool row_check(char x, int row,vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == x) {
                return false;
            }
        }

        return true;
    }
    bool col_check(char x, int col,vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == x) {
                return false;
            }
        }

        return true;
    }
    bool box_check(char x, int row, int col,vector<vector<char>>& board) {
        int row1 = 0;
        int row2 = 0;
        int col1 = 0;
        int col2 = 0;
        if ((row / 3) == 0) {
            row1 = 0;
            row2 = 2;
        } else if ((row / 3) == 1) {
            row1 = 3;
            row2 = 5;
        } else if ((row / 3) == 2) {
            row1 = 6;
            row2 = 8;
        }

        if ((col / 3) == 0) {
            col1 = 0;
            col2 = 2;
        } else if ((col / 3) == 1) {
            col1 = 3;
            col2 = 5;
        } else if ((col / 3) == 2) {
            col1 = 6;
            col2 = 8;
        }

        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                if (board[i][j] == x) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int idx = 1; idx <= 9; idx++) {
                        char c = idx + '0';
                        if (row_check(c, i,board) && col_check(c, j,board) &&
                            box_check(c, i, j,board)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        
        solve(board);
       

    }
};