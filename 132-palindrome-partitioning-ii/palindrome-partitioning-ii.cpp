class Solution {
public:
    vector<vector<bool>> isPal;

    void preComputePalindrome(string& s, int n) {
        isPal.assign(n, vector<bool>(n, false));
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    isPal[i][j] = true;
                } else if (gap == 1) {
                    isPal[i][j] = (s[i] == s[j]);
                } else {
                    if (s[i] == s[j] && isPal[i + 1][j - 1]) {
                        isPal[i][j] = true;
                    }
                }
            }
        }
    }

    int f(int i, int n, string& s, vector<int>& dp) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mincost = INT_MAX;

        for (int j = i; j < n; j++) {

            if (isPal[i][j]) {
                int cost = 1 + f(j + 1, n, s, dp);
                mincost = min(mincost, cost);
            }
        }

        return dp[i] = mincost;
    }

    int minCut(string s) {
        int n = s.size();

        preComputePalindrome(s, n);

        vector<int> dp(n + 1, -1);

        return f(0, n, s, dp) - 1;
    }
};