class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int k = goal;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int count = 0;
        vector<int> prefix(n, nums[0]);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int r = 0; r < n; r++) {
            if (mpp.find(prefix[r] - k) != mpp.end()) {
                count += mpp[prefix[r] - k];
            }
            mpp[prefix[r]]++;
        }
        return count;
    }
};