class Solution {
public:
    int n;

    int move(vector<int>& nums, vector<vector<int>>& dp, int last, int idx) {

        if (idx == n) {
            return 0;
        }

        if (dp[idx][last + 1] != -1) {
            return dp[idx][last + 1];
        }

        int pick = 0;

        if (last == -1 || nums[idx] > nums[last]) {
            pick = 1 + move(nums, dp, idx, idx + 1);
        }

        int not_pick = move(nums, dp, last, idx + 1);

        return dp[idx][last + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return move(nums, dp, -1, 0);
    }
};