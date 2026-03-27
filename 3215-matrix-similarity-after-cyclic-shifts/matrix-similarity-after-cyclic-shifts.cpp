class Solution {
public:
    int m;
    int n;
    vector<vector<int>> original;

    bool compare(vector<vector<int>>& mat) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != original[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    void shift(vector<vector<int>>& mat, int k) {
        for (int i = 0; i < k; i++) {
            // even indexed rows

            for (int j = 0; j < m; j = j + 2) {
                int start = mat[j][0];

                for (int x = 0; x <= n - 2; x++) {
                    mat[j][x] = mat[j][x + 1];
                }
                mat[j][n - 1] = start;
            }

            // odd indexed rows

            for (int j = 1; j < m; j = j + 2) {
                int start = mat[j][n - 1];

                for (int x = n - 1; x > 0; x--) {
                    mat[j][x] = mat[j][x - 1];
                }
                mat[j][0] = start;
            }
        }
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {

        m = mat.size();
        n = mat[0].size();
        k = k % n;
        original = mat;
        shift(mat, k);
        return compare(mat);
    }
};