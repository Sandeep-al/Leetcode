class Solution {
public:
    int minimumDeletions(string s) {
        int dp = 0;
        int bCount = 0;

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else {
                dp = min(dp + 1, bCount);
            }
        }
        return dp;
    }
};