class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int count = 0;

        int sum = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > k && l<=r) {
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};