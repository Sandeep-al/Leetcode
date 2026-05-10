class Solution {
public:
    vector<int> nums;
    vector<int> dp;

    int target;
    int n;

    int solve(int i) {

        if (i == n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = -1e8;

        for (int x = i + 1; x < n; x++) {

            if (abs(nums[x] - nums[i]) <= target) {

                ans = max(ans, 1 + solve(x));
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        this->nums = nums;
        this->target = target;

        n = nums.size();

        dp.resize(n, -1);

        int ans = solve(0);

        if (ans < 0)
            return -1;

        return ans;
    }
};