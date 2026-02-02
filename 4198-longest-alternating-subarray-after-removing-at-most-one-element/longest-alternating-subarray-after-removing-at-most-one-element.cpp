class Solution {
public:
    int getSign(int diff) {
        if (diff > 0)
            return 1;
        if (diff < 0)
            return -1;
        return 0;
    }

    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;

        vector<int> L(n, 1);
        for (int i = 1; i < n; i++) {
            int currDiff = nums[i] - nums[i - 1];

            if (currDiff != 0) {

                if (L[i - 1] == 1) {
                    L[i] = 2;
                } else {

                    int prevDiff = nums[i - 1] - nums[i - 2];
                    if (getSign(currDiff) != getSign(prevDiff)) {
                        L[i] = L[i - 1] + 1;
                    } else {

                        L[i] = 2;
                    }
                }
            }
        }

        vector<int> R(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            int currDiff = nums[i] - nums[i + 1];

            if (currDiff != 0) {
                if (R[i + 1] == 1) {
                    R[i] = 2;
                } else {

                    int nextDiff = nums[i + 1] - nums[i + 2];
                    if (getSign(currDiff) != getSign(nextDiff)) {
                        R[i] = R[i + 1] + 1;
                    } else {
                        R[i] = 2;
                    }
                }
            }
        }

        int maxLen = 0;
        for (int x : L)
            maxLen = max(maxLen, x);

        for (int i = 1; i < n - 1; i++) {

            int newDiff = nums[i + 1] - nums[i - 1];

            if (newDiff == 0)
                continue;

            bool leftCompatible = true;
            bool rightCompatible = true;

            if (L[i - 1] > 1) {
                int prevDiff = nums[i - 1] - nums[i - 2];
                if (getSign(newDiff) == getSign(prevDiff)) {
                    leftCompatible = false;
                }
            }

            if (R[i + 1] > 1) {
                int nextLinkDiff = nums[i + 2] - nums[i + 1];
                if (getSign(newDiff) == getSign(nextLinkDiff)) {
                    rightCompatible = false;
                }
            }

            if (leftCompatible && rightCompatible) {
                maxLen = max(maxLen, L[i - 1] + R[i + 1]);
            }
        }

        return maxLen;
    }
};