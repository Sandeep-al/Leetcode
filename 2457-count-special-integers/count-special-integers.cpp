class Solution {
public:
    string s;
    int n;
    // mask shows ki 0 to 9 konsi digit use ho chuki hy...
    int dp[11][2][2][1025];
    int solve(int idx, int tight, int started, int mask) {
        if (idx == n) {
            return started ? 1 : 0;
        }

        if (dp[idx][tight][started][mask] != -1) {
            return dp[idx][tight][started][mask];
        }

        int ans = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {
            int next_tight = tight && (digit == limit);
            int next_started = started || (digit > 0);

            if (next_started) {
                if ((mask & (1 << digit)) == 0) {
                    ans += solve(idx + 1, next_tight, next_started,
                                 mask | (1 << digit));
                }
            } else {
                ans += solve(idx + 1, next_tight, next_started, mask);
            }
        }

        return dp[idx][tight][started][mask] = ans;
    }
    int countSpecialNumbers(int n) {

        s=to_string(n);
        this->n=s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,1,0,0);
    }
};