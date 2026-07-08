class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int n = nums.size();
        int mini = INT_MAX;
        int curr_sum = 0;
        for (int right = 0; right < n; right++) {

            curr_sum += nums[right];
            while (curr_sum >= target) { // shrinkl till it is valid
                mini = min(mini, right - left + 1);
                curr_sum -= nums[left];
                left++;
            }
        }

        return (mini==INT_MAX)?0:mini;
    }
};