class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int difference = -500; difference <= 500; difference++) {
            dp.clear();
            for (int x : nums) {
                dp[x] = dp[x - difference] + 1;
                ans = max(ans, dp[x]);
            }
        }

        return ans;
    }
};