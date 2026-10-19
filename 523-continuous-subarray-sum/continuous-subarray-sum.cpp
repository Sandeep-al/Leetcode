class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        unordered_map<int, int> mpp;
        mpp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int curr = prefix[i] % k;

            if (mpp.find(curr) != mpp.end()) {
                if ((i - mpp[curr]) > 1) {
                    return 1;
                };
            } else {
                mpp[curr] = i;
            }
        }

        return 0;
    }
};