class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long double> suffix_product(n, 1);
        vector<long double> prefix_sum(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            suffix_product[i] = suffix_product[i + 1] * nums[i + 1];
        }
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        for(int i=0;i<n;i++){
            if(prefix_sum[i]==suffix_product[i]){
                return i;
            }
        }

        return -1;
    }
};