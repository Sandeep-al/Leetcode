class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        for (auto& it : nums) {
            mpp[it]++;
        }

        int maxi = -1;
        int maxi2 = -1;
        for (auto& it : mpp) {
            if (it.second == 1) {
                maxi = max(maxi, it.first);
            }
            maxi2 = max(maxi2, it.first);
        }

        if (k == 1) {
            return maxi;
        }

        if (k == n) {
            return maxi2;
        }

        int maxi3 = -1;

        if (mpp[nums[n - 1]] == 1) {
            maxi3 = max(maxi3, nums[n - 1]);
        }
        if (mpp[nums[0]] == 1) {
            maxi3 = max(maxi3, nums[0]);
        }

        return maxi3;
    }
};