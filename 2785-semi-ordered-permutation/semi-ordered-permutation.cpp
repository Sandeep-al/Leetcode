class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int x = -1;
        int y = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                x = i;
            } else if (nums[i] == nums.size()) {
                y = i;
            }
        }

        int ans = x - y + nums.size() - 1;

        if (x > y) {
            return ans - 1;
        }
        return ans;
    }
};