class Solution {
public:
    vector<int> nums;
    int n;
    long long dp[100001][2];
    long long solve(int idx, int parity) {
        // parity==1 add 0 means subtract

        if (idx == n) {
            return 0;
        }

        if(dp[idx][parity]!=-1){
            return dp[idx][parity];
        }

        long long not_take = solve(idx + 1, parity);
        int curr = (parity == 1) ? nums[idx] : -nums[idx];
        long long take = curr + solve(idx + 1, !parity);

        return dp[idx][parity]=max(take, not_take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        this->nums=nums;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 1);
    }
};