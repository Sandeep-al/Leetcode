class Solution {
public:
    int n;
    vector<int> nums;
    int dp[50005];
    int solve(int i) {

        if (i == n)
            return 0;
        if (dp[i] != INT_MAX) {
            return dp[i];
        }
        int maxi = INT_MIN;
        int curr_score = 0;
        for (int x = i; x < min(i + 3, n); x++) {
            curr_score += nums[x];
            maxi = max(maxi, curr_score - solve(x + 1));
        }

        return dp[i] = maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        nums = stoneValue;
        
        for (int i = 0; i < 50005; i++) {
            dp[i] = INT_MAX;
        }
        int ans = solve(0);
        if (ans > 0) {
            return "Alice";
        } else if (ans < 0) {
            return "Bob";
        }
        return "Tie";
    }
};