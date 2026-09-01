class Solution {
public:
    int m;
    int n;
    vector<int> nums;
    int dp[301][11];
    int solve(int idx, int day) {

        if (dp[idx][day] != -1) {
            return dp[idx][day];
        }
        if (day == m - 1 && idx < n) {

            int maxi = INT_MIN;
            for (int i = idx; i < n; i++) {
                maxi = max(maxi, nums[i]);
            }

            return maxi;
        }

        if (idx == n - 1)
            return INT_MAX;

        int maxi = INT_MIN;
        int output = INT_MAX;

        for (int i = idx; i < n - 1; i++) {
            maxi = max(maxi, nums[i]);
            int ans = solve(i + 1, day + 1);

            if (ans != INT_MAX) {
                output = min(output, ans + maxi);
            }
        }

        return dp[idx][day] = output;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        m = d;
        n = jobDifficulty.size();
        nums = jobDifficulty;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0, 0);
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};