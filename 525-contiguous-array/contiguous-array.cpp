class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0] == 0 ? -1 : 1;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (nums[i] == 0 ? -1 : 1);
        }
        unordered_map<int, int> mpp;
        mpp[0]=-1;
        int maxi=0;
        for (int r = 0; r < n; r++) {

            int curr_sum = prefix[r];
            if (mpp.find(curr_sum) != mpp.end()) {
                maxi = max(maxi, r - mpp[curr_sum]);
            }
            if (mpp.find(curr_sum) == mpp.end()) {
                mpp[curr_sum] = r;
            }
        }

        return maxi;
    }
};