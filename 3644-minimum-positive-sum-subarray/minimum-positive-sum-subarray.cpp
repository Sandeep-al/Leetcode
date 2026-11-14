class Solution {
public:
    int minimum_sum(int size, vector<int>& nums) {
        int total = 0;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            total += nums[i];

            if (i >= size) {
                total -= nums[i - size];
            }

            if (i >= size - 1 && total>0) {
                mini = min(mini, total);
            }
        }

        return mini;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int mini = INT_MAX;
        for (int i = l; i <= r; i++) {
            mini = min(mini, minimum_sum(i, nums));
        }

        return (mini==INT_MAX)?-1:mini;
    }
};