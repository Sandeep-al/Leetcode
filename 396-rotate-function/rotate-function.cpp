class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // lets start
        // calculate F0
        int n = nums.size();
        int f0 = 0;
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            f0 += (i * nums[i]);
            total_sum += nums[i];
        }
        int maxi = f0;
        vector<int> dp(n, 0);
        dp[0] = f0;
        for (int x = 1; x < n; x++) {
            dp[x] = dp[x - 1] + ((1 - n) * (nums[n-x])) + total_sum - nums[n-x];
            maxi = max(maxi, dp[x]);
        }

        

        return maxi;
    }
};