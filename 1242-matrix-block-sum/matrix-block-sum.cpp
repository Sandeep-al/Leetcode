class Prefix {
    vector<vector<long long>> P;

public:
    Prefix(int m, int n, vector<vector<int>>& nums) {
        P.assign(m + 1, vector<long long>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] +
                          nums[i - 1][j - 1];
            }
        }
    }

    long long query(int r1, int c1, int r2, int c2) {
        return P[r2][c2] - P[r2][c1 - 1] - P[r1 - 1][c2] + P[r1 - 1][c1 - 1];
    }
};
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        Prefix pref(m, n, mat);

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max((i - k), 0);
                int r2 = min((i + k), m - 1);
                int c1 = max((j - k), 0);
                int c2 = min((j + k), n - 1);

                ans[i][j] = pref.query(r1 + 1, c1 + 1, r2 + 1, c2 + 1);
            }
        }

        return ans;
    }
};
