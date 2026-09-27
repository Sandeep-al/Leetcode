class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int count = 0;
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {

            int curr = ((prefix[i] % k) + k) % k;

            if (mpp.find(curr) != mpp.end()) {
                count += mpp[curr];
            }

            mpp[curr] += 1;
        }

        return count;
    }
};