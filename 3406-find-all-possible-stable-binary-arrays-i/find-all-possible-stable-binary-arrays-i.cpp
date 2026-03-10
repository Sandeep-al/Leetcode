class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int zero, int one, int last, int cnt, int limit,
              vector<vector<vector<vector<int>>>> &dp) {

        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][last][cnt] != -1)
            return dp[zero][one][last][cnt];

        long long ans = 0;

        if (last == 0) {

            if (zero > 0 && cnt < limit)
                ans = (ans + solve(zero - 1, one, 0, cnt + 1, limit, dp)) % MOD;

            if (one > 0)
                ans = (ans + solve(zero, one - 1, 1, 1, limit, dp)) % MOD;
        }
        else {

            if (one > 0 && cnt < limit)
                ans = (ans + solve(zero, one - 1, 1, cnt + 1, limit, dp)) % MOD;

            if (zero > 0)
                ans = (ans + solve(zero - 1, one, 0, 1, limit, dp)) % MOD;
        }

        return dp[zero][one][last][cnt] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<vector<int>>>> dp(
            zero + 1,
            vector<vector<vector<int>>>(
                one + 1,
                vector<vector<int>>(
                    2,
                    vector<int>(limit + 1, -1)
                )
            )
        );

        long long ans = 0;

        if (zero > 0)
            ans = (ans + solve(zero - 1, one, 0, 1, limit, dp)) % MOD;

        if (one > 0)
            ans = (ans + solve(zero, one - 1, 1, 1, limit, dp)) % MOD;

        return ans;
    }
};