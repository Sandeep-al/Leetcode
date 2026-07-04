class Solution {
public:
    vector<int> nums;
    int n;
    long long dp[100001][2];
    long long solve(int idx, int parity) {
        // parity==1 add 0 means subtract

        if (idx == n) {
            return 0;
        }

        if (dp[idx][parity] != -1) {
            return dp[idx][parity];
        }

        long long not_take = solve(idx + 1, parity);
        int curr = (parity == 1) ? nums[idx] : -nums[idx];
        long long take = curr + solve(idx + 1, !parity);

        return dp[idx][parity] = max(take, not_take);
    }
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int parity = 0; parity <= 1; parity++) {

                long long not_take = dp[idx + 1][parity];
                int curr = (parity == 1) ? nums[idx] : -nums[idx];
                long long take = curr + dp[idx + 1][!parity];

                dp[idx][parity] = max(take, not_take);
            }
        }

        return dp[0][1];
    }
};