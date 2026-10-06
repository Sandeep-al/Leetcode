class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int count = 0;

        int sum = 0;

        for (int r = 0; r < n; r++) {

            if (nums[r] % 2 == 1) {
                sum++;
            }

            while (sum > k && l <= r) {
                if (nums[l] % 2 == 1) {
                    sum--;
                }
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};