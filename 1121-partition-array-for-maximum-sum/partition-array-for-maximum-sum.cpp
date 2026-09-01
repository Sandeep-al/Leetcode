class Solution {
public:
    int k;
    int n;
    vector<int> arr;
    int dp[502];
    int solve(int x) {

        if (x == n) {
            return 0;
        }

        if (dp[x] != -1)
            return dp[x];
        int limit = min(n - 1, x + k - 1);
        int maxi = INT_MIN;
        int maxi_ans = INT_MIN;
        for (int i = x; i <= limit; i++) {
            maxi = max(maxi, arr[i]);

            int len = i - x + 1;
            int value = len * maxi;

            maxi_ans = max(maxi_ans, value + solve(i + 1));
        }

        return dp[x] = maxi_ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        this->k = k;
        this->arr = arr;
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};