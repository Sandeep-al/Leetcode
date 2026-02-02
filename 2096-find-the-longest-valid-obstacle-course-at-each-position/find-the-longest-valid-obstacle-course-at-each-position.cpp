class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> temp;

        temp.push_back(nums[0]);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] >= temp.back()) {
                temp.push_back(nums[i]);

                dp[i] = temp.size();
            } else {
                int idx = upper_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[idx] = nums[i];

                dp[i] = idx + 1;
            }
        }

        return dp;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        return LIS(obstacles);
    }
};