class Solution {
public:
    vector<int> nums;
    // int dp[50005];
    // int solve(int i) {

    //     if (i == n)
    //         return 0;
    //     if (dp[i] != INT_MAX) {
    //         return dp[i];
    //     }
    //     int maxi = INT_MIN;
    //     int curr_score = 0;
    //     for (int x = i; x < min(i + 3, n); x++) {
    //         curr_score += nums[x];
    //         maxi = max(maxi, curr_score - solve(x + 1));
    //     }

    //     return dp[i] = maxi;
    // }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        nums = stoneValue;

        vector<int> dp(n + 1);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int maxi = INT_MIN;
            int curr_score = 0;

            for (int x = i; x < min(i + 3, n); x++) {
                curr_score += nums[x];
                maxi = max(maxi, curr_score - dp[x + 1]);
            }

            dp[i] = maxi;
        }

        if(dp[0]>0){
            return "Alice";
        }
        else if(dp[0]<0){
            return "Bob";
        }

        return "Tie";
    }
};