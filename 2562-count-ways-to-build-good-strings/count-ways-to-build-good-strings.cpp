class Solution {
public:
    int low, high, zero, one;
    const int MOD = 1e9 + 7;
    vector<int> dp;

    int solve(int len) {
        if (len > high) return 0;
        if (dp[len] != -1) return dp[len];

        long long ans = 0;

        if (len >= low && len <= high) {
            ans = 1;
        }

        if (len + zero <= high) {
            ans = (ans + solve(len + zero)) % MOD;
        }
        if (len + one <= high) {
            ans = (ans + solve(len + one)) % MOD;
        }

        return dp[len] = ans;
    }

    int countGoodStrings(int low1, int high1, int zero1, int one1) {
        low = low1;
        high = high1;
        zero = zero1;
        one = one1;

        dp.assign(high + 1, -1);
        return solve(0);
    }
};
