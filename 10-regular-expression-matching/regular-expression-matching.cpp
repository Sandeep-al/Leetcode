class Solution {
public:
    int m, n;
    int dp[21][21];

    bool move(string& s, string& p, int i, int j) {

        if (j == n) {
            return i == m;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool first_match = (i < m) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < n && p[j + 1] == '*') {

            return dp[i][j] = move(s, p, i, j + 2) ||
                              (first_match && move(s, p, i + 1, j));
        }

        if (first_match) {
            return dp[i][j] = move(s, p, i + 1, j + 1);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();

        memset(dp, -1, sizeof(dp));
        return move(s, p, 0, 0);
    }
};