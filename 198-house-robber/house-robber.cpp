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
        int next1 = 0;
        int next2 = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            int np = next1;

            // pick
            int p = nums[idx] + next2;

            next2 = next1;

            next1 = max(np, p);
        }

        return next1;
    }
};