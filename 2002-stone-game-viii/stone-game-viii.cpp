class Solution {
public:
    vector<int> prefix;
    int n;
    vector<int> nums;
    int dp[100005];
    int solve(int i) {

        if (i == n-1)
            return prefix[n-1];
        if (dp[i] != INT_MAX) {
            return dp[i];
        }

        int maxi = INT_MIN;
        maxi = max(maxi, solve(i + 1));
        maxi = max(maxi, prefix[i] - solve(i + 1));

        return dp[i] = maxi;
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        nums = stones;
        prefix.assign(n, 0);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for(int i=0;i<100005;i++){
            dp[i]=INT_MAX;
        }
        return solve(1);
    }
};