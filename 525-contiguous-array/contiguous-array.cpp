class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        // (prefix[r+1]-prefix[l])== [l....r]
        // (r-l+1)/2  also r-l+1 should be even

        // if (2 * prefix[i] - i == 2 * prefix[j] - j)

        int n = nums.size();
        unordered_map<int, int> mpp;

        vector<int> prefix(n + 1, 0);   

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int maxi = 0;
        mpp[0]=0;
        for (int i = 1; i <= n; i++) {
            if (mpp.find(2 * prefix[i] - i) != mpp.end()) {
                maxi = max(maxi, i - mpp[2 * prefix[i] - i]);
            } else {
                mpp[2 * prefix[i] - i] = i;
            }
        }

        return maxi;
    }
};