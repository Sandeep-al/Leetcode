class Solution {
public:
    string s;
    string t;
    int m;
    int n;
    int dp[1001][1001];
    int solve(int idx1, int idx2) {

        if (idx1 == m) {

            if (idx2 == n) {
                return 1;
            }
            return 0;
        }
        if (idx2 == n) {
            return 1;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int count = 0;

        if (s[idx1] == t[idx2]) {
            count = count + solve(idx1 + 1, idx2 + 1);
        }

        count = count + solve(idx1 + 1, idx2);

        return dp[idx1][idx2] = count;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        m = s.size();
        n = t.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};