class Solution {
public:
    int n;
    int givemax(vector<int>& nums, vector<int>& dp, int idx) {

        if (idx >= n) {
            return 0;
        }
        if (idx == n - 1) {
            return nums[n - 1];
        }

        if (dp[idx] != -1)
            return dp[idx];
        // not pick

        int np = givemax(nums, dp, idx + 1);

        // pick
        int p = nums[idx] + givemax(nums, dp, idx + 2);

        return dp[idx] = max(np, p);
    }
    int rob(vector<int>& nums) {

        n = nums.size();
        vector<int> dp(n + 2, -1);
        dp[n] = 0;
        dp[n + 1] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            int np = dp[idx + 1];

            // pick
            int p = nums[idx] + dp[idx + 2];

            dp[idx] = max(np, p);
        }

        return dp[0];
    }
};