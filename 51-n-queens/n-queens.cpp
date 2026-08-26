class Solution {
public:
    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;
    vector<vector<string>> final_ans;
    vector<string> curr;

    int n;
    void solve(int idx) {
        if (idx == n) {
            final_ans.push_back(curr);

            return;
        }
        string currs(n, '.');
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag1[idx - i + n - 1] && !diag2[idx + i]) {
                currs[i] = 'Q';
                col[i] = 1;
                diag1[idx - i + n - 1] = 1;
                diag2[idx + i] = 1;
                curr.push_back(currs);
                solve(idx + 1);
                curr.pop_back();
                currs[i] = '.';
                col[i] = 0;
                diag1[idx - i + n - 1] = 0;
                diag2[idx + i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        this->n = n;
        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        solve(0);
        return final_ans;
    }
};