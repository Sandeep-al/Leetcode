class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int sum=0;
        unordered_map<int, int> mpp;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;
            sum+=nums[r];

            while (mpp[nums[r]] > 1 && l <= r) {
                mpp[nums[l]]--;
                sum-=nums[l];
                
                l++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};