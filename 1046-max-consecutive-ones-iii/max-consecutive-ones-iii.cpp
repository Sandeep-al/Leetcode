class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int count = 0;
        int l=0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                count++;
            }

            while (count > k) {
                if (nums[l] == 0) {
                    count--;
                }

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};