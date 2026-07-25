class SubgridSum {
private:
    vector<vector<long long>> prefix;

public:
    SubgridSum(const vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return;

        int m = grid.size();
        int n = grid[0].size();
        prefix.assign(m + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] +
                                       prefix[i + 1][j] - prefix[i][j];
            }
        }
    }

    long long query(int r1, int c1, int r2, int c2) {
        return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] -
               prefix[r2 + 1][c1] + prefix[r1][c1];
    }
};

class Difference2D {
private:
    int rows, cols;
    vector<vector<int>> diff;

public:
    Difference2D(int m, int n) {
        rows = m;
        cols = n;

        diff.assign(m + 2, vector<int>(n + 2, 0));
    }

    void update(int r1, int c1, int r2, int c2, int val = 1) {
        diff[r1 + 1][c1 + 1] += val;
        diff[r2 + 2][c2 + 2] += val;
        diff[r1 + 1][c2 + 2] -= val;
        diff[r2 + 2][c1 + 1] -= val;
    }

    vector<vector<int>> getActualGrid() {
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        vector<vector<int>> temp(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {

                temp[i][j] = diff[i][j] + temp[i - 1][j] + temp[i][j - 1] -
                             temp[i - 1][j - 1];

                result[i - 1][j - 1] = temp[i][j];
            }
        }
        return result;
    }
};

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight,
                         int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();

        SubgridSum pref(grid);
        Difference2D diff(m, n);

        for (int i = 0; i <= m - stampHeight; i++) {
            for (int j = 0; j <= n - stampWidth; j++) {
                int r2 = i + stampHeight - 1;
                int c2 = j + stampWidth - 1;

                if (pref.query(i, j, r2, c2) == 0) {
                    diff.update(i, j, r2, c2, 1);
                }
            }
        }

        vector<vector<int>> stampCount = diff.getActualGrid();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && stampCount[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};