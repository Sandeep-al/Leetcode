class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        
        long long parity_0 = 0;
        long long parity_1 = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int parity = 0; parity <= 1; parity++) {

                long long curr_parity = (parity == 0) ? parity_0 : parity_1;
                long long not_take = curr_parity;
                int curr = (parity == 1) ? nums[idx] : -nums[idx];

                curr_parity = (parity == 0) ? parity_1 : parity_0;
                long long take = curr + curr_parity;

                long long res = max(take, not_take);

                if (parity == 0) {
                    parity_0 = res;
                } else {
                    parity_1 = res;
                }
            }
        }

        return parity_1;
    }
};