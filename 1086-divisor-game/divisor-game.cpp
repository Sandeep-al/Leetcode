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
        return can_alice_win(n, 1);
    }
};