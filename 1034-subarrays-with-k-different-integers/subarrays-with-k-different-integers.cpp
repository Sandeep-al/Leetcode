class Solution {
public:
    int solve(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        int l = 0;
        int n = nums.size();
        int count = 0;

        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;

            while (mpp.size() > k && l <= r) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};