class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum =nums[0];
        nums[0]=-1;
        sort(nums.begin(),nums.end());
        return sum+nums[1]+nums[2];
    }
};