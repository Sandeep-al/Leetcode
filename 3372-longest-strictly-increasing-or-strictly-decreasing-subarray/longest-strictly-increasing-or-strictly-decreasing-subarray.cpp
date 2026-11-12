class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int strictly_i = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                curr = 1;
            } else {
                curr++;
            }

            strictly_i = max(strictly_i, curr);
        }

        int strictly_d = 1;
        curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i - 1]) {
                curr = 1;
            } else {
                curr++;
            }

            strictly_i = max(strictly_i, curr);
        }

        return max(strictly_i,strictly_d);
    }
};