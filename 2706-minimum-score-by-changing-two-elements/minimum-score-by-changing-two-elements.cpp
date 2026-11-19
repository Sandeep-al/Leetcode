class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 25 31 65 72 74 79
        //

        return min(nums[n - 2] - nums[1],
                   min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]));
    }
};