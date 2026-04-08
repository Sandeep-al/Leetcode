class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> m1;

        for (int i = 0; i < nums.size(); i++) {
            if (m1.find(target-nums[i]) != m1.end()) {
                return {m1[target-nums[i]],i};
            }
            else{
                m1[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};