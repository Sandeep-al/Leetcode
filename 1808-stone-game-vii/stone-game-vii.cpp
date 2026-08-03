class Solution {
public:
    vector<int> prefix;
    vector<int> nums;
    int n;
    int dp[1001][1001];
    int solve(int i, int j) {

        if (i == j) {
            return 0;
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int maxi = INT_MIN;

        int curr_sum1 = prefix[j - 1] - ((i == 0) ? 0 : prefix[i - 1]);
        int curr_sum2 = prefix[j] - prefix[i];

        maxi = max(maxi, curr_sum1 - solve(i, j - 1));
        maxi = max(maxi, curr_sum2 - solve(i + 1, j));

        return dp[i][j]=maxi;
    }
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        nums = stones;

        prefix.assign(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=INT_MAX;
            }
        }
        return solve(0, n - 1);
    }
};