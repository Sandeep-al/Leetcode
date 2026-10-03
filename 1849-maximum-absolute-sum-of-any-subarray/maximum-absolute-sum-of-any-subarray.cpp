class Solution {
public:
    pair<int,int> dp[100005];
    pair<int, int> solve(int idx, vector<int>& nums) { // max +ve,max-ve sum
        if (idx == nums.size()) {
            return {0, 0};
        }

        if(dp[idx].first!=INT_MAX && dp[idx].second!=INT_MAX){
            return dp[idx];
        }
        int curr = nums[idx];
        auto [x, y] = solve(idx + 1, nums);

        x += nums[idx];
        y += nums[idx];

        int maxi = max(0, max(max(curr, x), y));
        int mini = min(0, min(min(curr, x), y));

        return dp[idx]={maxi, mini};
    }
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<100005;i++){
            dp[i]={INT_MAX,INT_MAX};
        }
        for (int i = 0; i < n; i++) {
            auto [x, y] = solve(i, nums);
            maxi = max(maxi, x);
            mini = min(mini, y);
        }

        return max(abs(maxi), abs(mini));

        
    }
};