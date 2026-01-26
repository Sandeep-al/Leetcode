class Solution {
public:
     int dp[101][10001];

    int solve(int k, int n) {

        if (n == 0 || n == 1)
            return n;

        if (k == 1)
            return n;

        if (dp[k][n] != -1)
            return dp[k][n];

        int mn = INT_MAX;
        int low = 1, high = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            int broken = solve(k - 1, mid - 1);

            int not_broken = solve(k, n - mid);

            int worst_case = 1 + max(broken, not_broken);

            mn = min(mn, worst_case);

            if (broken < not_broken) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return dp[k][n] = mn;
    }

    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(2, n);
    }
};