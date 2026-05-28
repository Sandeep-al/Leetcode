class Solution {
public:
    void rotate(vector<char>& x) {
        int n = x.size();

        for (int j = n - 1; j >= 0; j--) {
            if (x[j] == '#') {
                int i = j;
                while (i + 1 < n && x[i + 1] != '#' && x[i + 1] != '*') {
                    swap(x[i], x[i + 1]);
                    i++;
                }
            }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            // process each row

            //. doesnt matter ..... '*' doesnt matter
            // move each # from end till it reaches n-1 or another # or *

            // 0th row is actually last column xth row becomes m-x-1 column

            // and column position becomes row position

            rotate(boxGrid[i]);
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = boxGrid[i][j];
            }
        }

        return ans;
    }
};