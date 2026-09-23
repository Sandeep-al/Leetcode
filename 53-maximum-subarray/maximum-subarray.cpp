class Solution {
public:
    int dp[100005];
    int solve(int idx, vector<int>& nums, int n) {

        if (idx == n)
            return 0;

        if (dp[idx] != INT_MAX) {
            return dp[idx];
        }

        // take this and get new sum
        // start new subarray from here

        int ans1 = nums[idx] + solve(idx + 1, nums, n);
        int ans2 = nums[idx];

        return dp[idx] = max(ans1, ans2);
    }
    int maxSubArray(vector<int>& nums) {
        for (int i = 0; i < 100005; i++) {
            dp[i] = INT_MAX;
        }
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, solve(i, nums, n));
        }
        return maxi;
    }
};