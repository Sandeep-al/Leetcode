class Solution {
public:
    vector<vector<string>> final_ans;
    int n;
    bool can_we_place(vector<vector<char>>& temp, int x, int y) {
        bool ans = true;
        for (int j = 0; j < n; j++) {
            if (temp[x][j] == 'Q')
                ans = false;
            if (temp[j][y] == 'Q')
                ans = false;
        }
        int i = x, j = y;

        while (i > 0 && j > 0) {
            i--;
            j--;
        }

        while (i < n && j < n) {
            if (temp[i][j] == 'Q')
                ans = false;
            i++;
            j++;
        }

        i = x;
        j = y;

        while (i > 0 && j < n - 1) {
            i--;
            j++;
        }

        while (i < n && j >= 0) {
            if (temp[i][j] == 'Q')
                ans = false;
            i++;
            j--;
        }

        return ans;
    }
    void solve(vector<vector<char>>& temp, int row) {
        if (row == n) {
            vector<string> t;
            for (int i = 0; i < n; i++) {
                string x = "";
                for (int j = 0; j < n; j++) {
                    x.push_back(temp[i][j]);
                }
                t.push_back(x);
            }
            final_ans.push_back(t);

            return ;
        }

        for (int i = 0; i < n; i++) {
            if (can_we_place(temp, row, i)) {
                temp[row][i] = 'Q';
                solve(temp, row + 1);
                temp[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<char>> temp(n, vector<char>(n, '.'));

        solve(temp, 0);
        return final_ans;
    }
};