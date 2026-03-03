class Solution {
public:
    string s1;
    string s2;
    string s3;
    int m;
    int n;
    vector<vector<int>> dp;
    bool solve(int idx1, int idx2) {
        if (idx1 == m && idx2 == n) {

            return true;
        }
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (idx1 < m && s3[idx1 + idx2] == s1[idx1]) {

            if (solve(idx1 + 1, idx2)) {
                return dp[idx1][idx2] = true;
            }
        }

        if (idx2 < n && s3[idx1 + idx2] == s2[idx2]) {

            if (solve(idx1, idx2 + 1)) {
                return dp[idx1][idx2] = true;
            }
        }

        return dp[idx1][idx2] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;

        m = s1.size();
        n = s2.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0);
    }
};