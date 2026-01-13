class Solution {
public:
    // Ye tera purana 'givemax' logic hai (Same to Same)
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case for empty sub-array
        vector<int> dp(n + 1, -1);
        return givemax(nums, dp, 0, n);
    }

    int givemax(vector<int>& nums, vector<int>& dp, int idx, int n) {
        if (idx >= n) return 0;
        if (idx == n - 1) return nums[idx];

        if (dp[idx] != -1) return dp[idx];

        // Pick vs Not Pick
        int pick = nums[idx] + givemax(nums, dp, idx + 2, n);
        int not_pick = givemax(nums, dp, idx + 1, n);

        return dp[idx] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // Edge Case: Agar circle mein ek hi ghar hai
        if (n == 1) return nums[0];

        // Case 1: First ghar ko chhod do (Index 1 se n-1 tak)
        vector<int> temp1;
        for(int i=1; i<n; i++) temp1.push_back(nums[i]);

        // Case 2: Last ghar ko chhod do (Index 0 se n-2 tak)
        vector<int> temp2;
        for(int i=0; i<n-1; i++) temp2.push_back(nums[i]);

        // Dono scenarios mein se best nikaal lo
        return max(solve(temp1), solve(temp2));
    }
};