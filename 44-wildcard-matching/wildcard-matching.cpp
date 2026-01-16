class Solution {
public:
    int m;
    int n;
    bool move(string& s, string& p, int idx1, int idx2,
              vector<vector<int>>& dp) {

        if (idx1 == m && idx2 == n) {
            return true;
        }

        if (idx2 == n && idx1 < m) {
            return false;
        }

        if (idx1 == m) {
            for (int k = idx2; k < p.size(); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }

            return true;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if (s[idx1] == p[idx2] || p[idx2] == '?') {
            return dp[idx1][idx2]=move(s, p, idx1 + 1, idx2 + 1, dp);
        }

        else if (p[idx2] == '*') {

            int consume = move(s, p, idx1 + 1, idx2, dp);
            int die = move(s, p, idx1, idx2 + 1, dp);

            return dp[idx1][idx2]=consume || die;
        }

        return dp[idx1][idx2]=false;
    }
    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return move(s, p, 0, 0, dp);
    }
};