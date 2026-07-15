class Solution {
public:
    int n;
    int dp[9][1050];
    int solve(int idx, int bitmask) {

        if (idx == n)
            return 0;
        if(dp[idx][bitmask]!=-1) return dp[idx][bitmask];
        int ans = 0;

        for (int i = 0; i < 10; i++) {

            if (idx == 0 && i == 0)
                continue;

            if (!(bitmask & (1 << i))) {

                ans += 1 + solve(idx + 1, (bitmask | (1 << i)));
            }
        }

        return dp[idx][bitmask]=ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        this->n = n;
        if (n == 0)
            return 1;
        memset(dp,-1,sizeof(dp));
        return solve(0, 0) + 1;
    }
};