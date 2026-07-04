class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        long long parity_0 = 0;
        long long parity_1 = 0;

        for (int i = n - 1; i >= 0; i--) {

            parity_0 = max(parity_0, -1LL * nums[i] + parity_1);
            parity_1 = max(parity_1, 1LL * nums[i] + parity_0);
        }

        return parity_1;
    }
};