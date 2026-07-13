class Solution {
public:
    int dp[1001][2];
    bool can_alice_win(int x, int alice) {

        if (x == 0) {
            return dp[x][alice] = 0;
        }

        if (dp[x][alice] != -1) {
            return dp[x][alice];
        }
        for (int i = 1; i < x; i++) {
            if (x % i == 0) {
                if (can_alice_win(x - i, 1 - alice) == 0) {
                    return dp[x][alice] = 1;
                }
            }
        }

        return dp[x][alice] = 0;
    }
    bool divisorGame(int n) {

        memset(dp, -1, sizeof(dp));

        dp[0][0] = 0;
        dp[0][1] = 0;

        for (int idx = 1; idx <= n; idx++) {
            for (int alice = 0; alice <= 1; alice++) {
                dp[idx][alice] = 0 ;
                for (int i = 1; i < idx; i++) {
                    if (idx % i == 0) {

                        if (dp[idx - i][1 - alice] == 0) {
                            dp[idx][alice] = 1;
                            
                        }
                    }
                }

                
            }
        }

        return dp[n][1];
    }
};