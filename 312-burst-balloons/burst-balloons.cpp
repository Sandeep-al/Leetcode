class Solution {
public:
    int n;
    vector<int> nums;
    int dp[305][305];
    int solve(int l, int r) {

        if (l > r)
            return 0;

        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        // try every possible point as its gonna burst in last
        int maxi = 0;
        for (int candidate = l; candidate <= r; candidate++) {
            int curr = solve(l, candidate - 1) +
                       (nums[l - 1] * nums[candidate] * nums[r + 1]) +
                       solve(candidate + 1, r);

            maxi = max(maxi, curr);
        }

        return dp[l][r] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        this->nums = nums;
        this->nums.push_back(1);
        this->nums.insert(this->nums.begin(), 1);
        n = this->nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(1, n - 2);
    }
};