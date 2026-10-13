class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (auto& it : nums) {
            if (it < 0)
                it = it * (-1);
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long maxi = 0;

        int i = n / 2;
        for (int x = i; x < n; x++) {
            maxi += (long long)nums[x] * (long long)nums[x];
        }

        for (int x = 0; x < i; x++) {
            maxi -= (long long)nums[x] * (long long)nums[x];
        }

        return maxi;
    }
};