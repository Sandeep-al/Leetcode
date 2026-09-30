class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int x = 2 * k + 1;
        int n = nums.size();
        long long sum = 0;
        vector<int> ans(n, -1);

        

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (i >= x) {
                sum -= nums[i - x];
            }

            if (i >= x - 1) {
                ans[i - k] = (sum / x);
            }
        }

        return ans;
    }
};