class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int ans = 0;
        map<char, int> mpp;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;

            while (mpp[nums[r]] > 1 && l <= r) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            if (mpp.size() == r - l + 1) {
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};