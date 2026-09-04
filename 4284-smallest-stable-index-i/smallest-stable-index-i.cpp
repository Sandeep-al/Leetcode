class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefix_max(nums.size(), nums[0]);
        vector<int> prefix_min(nums.size(), nums[nums.size() - 1]);

        for (int i = 1; i < nums.size(); i++) {
            prefix_max[i] = max(prefix_max[i - 1], nums[i]);
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            prefix_min[i] = min(prefix_min[i + 1], nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if((prefix_max[i]-prefix_min[i])<=k){
                return i;
            }
        }

        return -1;
    }
};