class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<long long>> dp;

    vector<vector<bool>> visited;
    long long solve(int i, int trend) {

        if (i == n - 1) {
            if (trend == 3)
                return arr[i];
            return LLONG_MIN;
        }
        if (visited[i][trend]) {
            return dp[i][trend];
        }
        long long ans = LLONG_MIN;
        int curr = arr[i];
        int next = arr[i + 1];

        if (trend == 0) {
            // skip
            ans = solve(i + 1, 0);

            // start increasing
            if (next > curr) {
                long long take = solve(i + 1, 1);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
        }

        // trend 1 : increasing
        else if (trend == 1) {
            // continue increasing
            if (next > curr) {
                long long take = solve(i + 1, 1);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
            // transition to decreasing
            else if (next < curr) {
                long long take = solve(i + 1, 2);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
        }

        // trend 2 : decreasing
        else if (trend == 2) {
            // continue decreasing
            if (next < curr) {
                long long take = solve(i + 1, 2);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
            // transition to final increasing
            if (next > curr) {
                long long take = solve(i + 1, 3);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
        }

        // trend 3 : final increasing
        else if (trend == 3) {

            // option 1: stop here
            ans = curr;

            // option 2: continue increasing
            if (next > curr) {
                long long take = solve(i + 1, 3);
                if (take != LLONG_MIN)
                    ans = max(ans, curr + take);
            }
        }

        visited[i][trend] = true;
        dp[i][trend] = ans;
        return ans;
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<long long>(4, 0));
        visited.assign(n, vector<bool>(4, false));
        arr = nums;
        return solve(0, 0);
    }
};
