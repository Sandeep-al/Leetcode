class Solution {
public:
    vector<int> nums;
    int dp[21][21];
    int solve(int i, int j) {
        if (i > j) {
            return 0;
        }
        // case 1 take nums[i];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi = 0;

        int takeLeft = nums[i] + min(solve(i + 2, j), solve(i + 1, j - 1));

        int takeRight = nums[j] + min(solve(i, j - 2), solve(i + 1, j - 1));

        return dp[i][j]=max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        int target = 0;
        for (auto& it : nums) {
            target += it;
        }
        memset(dp,-1,sizeof(dp));
        target = ceil((double)target / 2.0);
        int ans = solve(0, n - 1);
        cout << ans;
        if (ans >= target) {
            return true;
        }
        return false;
    }
};