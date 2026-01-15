class Solution {
public:
    int t;
    
    unordered_map<int, unordered_map<int, int>> dp;

    int move(vector<int>& nums, int sum, int idx) {
        
        
        if (idx < 0) {
            return sum == t;
        }

        
        if (dp.count(idx) && dp[idx].count(sum)) {
            return dp[idx][sum];
        }

        
        int positive = move(nums, sum + nums[idx], idx - 1);
        int negative = move(nums, sum - nums[idx], idx - 1);

        
        return dp[idx][sum] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        dp.clear(); 
        int n = nums.size();
        return move(nums, 0, n - 1);
    }
};