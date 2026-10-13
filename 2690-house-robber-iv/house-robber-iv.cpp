class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int idx, int maxi) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        // take it
        int take = 0;
        if (nums[idx] <= maxi) {
            take = 1 + solve(nums,dp, idx + 2, maxi);
        }

        int not_take = solve(nums,dp, idx + 1, maxi);

        return dp[idx] = max(take, not_take);
    }
    int minCapability(vector<int>& nums, int k) {
        // with only this maximum allowed how many houses u can steal
        vector<int> dp(nums.size(), -1);

        int lo = 0;
        int hi = INT_MAX;

        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;
            fill(dp.begin(), dp.end(), -1);
            if (solve(nums, dp, 0, mid) >= k) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};