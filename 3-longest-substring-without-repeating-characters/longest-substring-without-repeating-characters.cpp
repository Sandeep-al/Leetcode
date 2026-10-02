class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int ans = 0;
        unordered_map<char, int> mpp;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;

            while (mpp[nums[r]] > 1 && l <= r) {
                mpp[nums[l]]--;
                
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};