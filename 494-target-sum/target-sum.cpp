class Solution {
public:
   
    int offset; 
    
    int move(vector<int>& nums, int sum, int target, int idx, vector<vector<int>>& dp) {
        
        if (idx < 0) {
            return sum == target;
        }

        
        if (dp[idx][sum + offset] != -1) { 
            return dp[idx][sum + offset];
        }

       
        int positive = move(nums, sum + nums[idx], target, idx - 1, dp);
        int negative = move(nums, sum - nums[idx], target, idx - 1, dp);

       
        return dp[idx][sum + offset] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int x : nums) totalSum += x;
        
        
        offset = totalSum;
        
        
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
        
        return move(nums, 0, target, n - 1, dp);
    }
};