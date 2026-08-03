class Solution {
public:
    int n;
    vector<int> nums;
    int dp[101][205][2];
    int solve(int i, int M, int turn) {

        if (i == n)
            return 0;
        if (dp[i][M][turn] != -1) {
            return dp[i][M][turn];
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int curr_score = 0;
        if (turn == 1) { // alice turn
            for (int x = i; x <= min(2 * M + i - 1, n - 1); x++) {
                curr_score += nums[x];
                maxi =
                    max(maxi, curr_score + solve(x + 1, max(x - i + 1, M), 0));
            }

            return dp[i][M][turn] = maxi;
        } else {
            for (int x = i; x <= min(2 * M + i - 1, n - 1); x++) {

                mini = min(mini, solve(x + 1, max(x - i + 1, M), 1));
            }

            return dp[i][M][turn] = mini;
        }

        return 0;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        nums = piles;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1);
    }
};