class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {

            if (i > 0) {
                prefix[i] = prefix[i - 1] ^ prefix[i];
            }
            int curr = prefix[i] ^ nums[i];
            if (curr == 0) {
                count++;
                if (i + k >= n + 1) {
                    return -1;
                }
                prefix[i] ^= 1;
                prefix[i + k] ^= 1;
            } else {
                continue;
            }
        }

        return count;
    }
};