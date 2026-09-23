class Solution {
public:
    pair<int, int> dp[100005];
    pair<int, int> solve(int idx, vector<int>& nums, int n) {

        if (idx == n)
            return {1, 1};

        if (dp[idx].first != INT_MAX && dp[idx].second != INT_MAX) {
            return dp[idx];
        }

        // take this and get new sum
        // start new subarray from here

        int ans1 = nums[idx] * solve(idx + 1, nums, n).first;
        int ans2 = nums[idx] * solve(idx + 1, nums, n).second;
        int ans3 = nums[idx];

        return dp[idx] = {max(ans1, max(ans2, ans3)),
                          min(ans1, min(ans2, ans3))};
    }
    int maxProduct(vector<int>& nums) {
        for (int i = 0; i < 100005; i++) {
            dp[i] = {INT_MAX, INT_MAX};
        }
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, solve(i, nums, n).first);
        }
        return maxi;
    }
};