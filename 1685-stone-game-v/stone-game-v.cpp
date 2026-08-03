class Solution {
public:
    vector<int> prefix;
    vector<int> nums;
    int n;
    int dp[501][501];
    int solve(int i, int j) {

        if (i > j)
            return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int sum_ij = prefix[j] - ((i == 0) ? 0 : prefix[i - 1]);
        int curr_sum = 0;
        int maxi = 0;
        for (int x = i; x <= j; x++) {
            curr_sum += nums[x];

            if (curr_sum * 2 == sum_ij) { // two equal partitions ..take anyone

                maxi = max(maxi, curr_sum + solve(i, x));
                maxi = max(maxi, curr_sum + solve(x + 1, j));
            }

            else if (curr_sum * 2 < sum_ij) {
                maxi = max(maxi, curr_sum + solve(i, x));
            } else {
                maxi = max(maxi, sum_ij - curr_sum + solve(x + 1, j));
            }
        }

        return dp[i][j] = maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        nums = stoneValue;
        n = nums.size();
        prefix.assign(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1);
    }
};