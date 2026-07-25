class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> prefix(n);
        
        prefix[0] = nums[0] % p;
        for (int i = 1; i < n; i++) {
            prefix[i] = (prefix[i - 1] + nums[i]) % p;
        }

        int target = prefix[n - 1];
        if (target == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int mini = n;

        for (int r = 0; r < n; r++) {
            int curr = prefix[r];
            int needed = (curr - target + p) % p;

            if (mpp.find(needed) != mpp.end()) {
                mini = min(mini, r - mpp[needed]);
            }

            mpp[curr] = r;
        }

        return (mini == n) ? -1 : mini;
    }
};