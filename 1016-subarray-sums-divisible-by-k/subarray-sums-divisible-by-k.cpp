class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        //(prefix[r+1]-prefix[l])%k=0;
        // prefix[r+1]%k=prefix[l]%k;
        //
        int count = 0;

        mpp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int curr = ((prefix[i] % k) + k) % k;

            if (mpp.find(curr) != mpp.end()) {
                count += mpp[curr];
            }

            mpp[curr]++;
        }

        return count;
    }
};