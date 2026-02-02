class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;

        vector<int> L(n, 1);
        int maxLenWithoutReplace = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                L[i] = L[i - 1] + 1;
            }
            maxLenWithoutReplace = max(maxLenWithoutReplace, L[i]);
        }

        vector<int> R(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                R[i] = R[i + 1] + 1;
            }
        }

        int maxLen = maxLenWithoutReplace;

        for (int i = 0; i < n; i++) {

            int leftSide = (i > 0) ? L[i - 1] + 1 : 1;

            int rightSide = (i < n - 1) ? R[i + 1] + 1 : 1;

            int bridge = 0;
            if (i > 0 && i < n - 1 && nums[i - 1] <= nums[i + 1]) {
                bridge = L[i - 1] + 1 + R[i + 1];
            }

            maxLen = max({maxLen, leftSide, rightSide, bridge});
        }

        return maxLen;
    }
};