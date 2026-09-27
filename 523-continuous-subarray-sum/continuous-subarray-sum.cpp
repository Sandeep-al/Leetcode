class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> mpp;
        mpp[0] = -1;
        long long count = 0;
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {

            long long curr = ((prefix[i] % k) + k) % k;

            if (mpp.find(curr) != mpp.end()) {
                if (i - mpp[curr] >= 2) {
                    return 1;
                }
            } else {
                mpp[curr] = i;
            }
        }

        return 0;
    }
};