class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<long long> dp;

    long long solve(int i) {
        if (i < 0) return 0;
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i == 2) return 2;

        if (dp[i] != -1) return dp[i];

        return dp[i] = (2 * solve(i - 1) + solve(i - 3)) % MOD;
    }

    int numTilings(int n1) {
        n = n1;
        dp.assign(n + 1, -1);
        return solve(n);
    }
};
