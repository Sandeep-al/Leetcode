class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mpp[nums[i]]++;

            if (i >= k) {
                mpp[nums[i - k]]--;
                if (mpp[nums[i - k]] == 0) {
                    mpp.erase(nums[i - k]);
                }
                sum-=nums[i-k];
            }

            if (i >= k - 1) {
                if (mpp.size() == k) {
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};