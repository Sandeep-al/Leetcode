class Solution {
public:
    int n;
    int dp[5001][4][4][4];
    const int mod=1e9+7;
    int solve(int idx, int prev_i, int prev_j, int prev_k) {
        if (idx == n)
            return 1;

        int ans = 0;
        if (dp[idx][prev_i + 1][prev_j + 1][prev_k + 1] != -1)
            return dp[idx][prev_i + 1][prev_j + 1][prev_k + 1];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {

                    if (i != j && j != k && i != prev_i && j != prev_j &&
                        k != prev_k) {
                        ans = (ans + solve(idx + 1, i, j, k))% mod;
                    }
                }
            }
        }

        return dp[idx][prev_i + 1][prev_j + 1][prev_k + 1] = ans;
    }
    int numOfWays(int n) {
        this->n = n;
        memset(dp,-1,sizeof(dp));
        return solve(0, -1, -1, -1);
    }
};