class Solution {
public:
    vector<int> nums;
    int dp[501][501];
    int solve(int i, int j) {
        if (i > j) {
            return 0;
        }
       
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        

        int takeLeft = nums[i] + min(solve(i + 2, j), solve(i + 1, j - 1));

        int takeRight = nums[j] + min(solve(i, j - 2), solve(i + 1, j - 1));

        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        this->nums = piles;
        int n = nums.size();
        int target = 0;
        for (auto& it : nums) {
            target += it;
        }
        memset(dp,-1,sizeof(dp));
        target = target / 2;
        int ans = solve(0, n - 1);
        
        if (ans > target) {
            return true;
        }
        return false;
    }
};