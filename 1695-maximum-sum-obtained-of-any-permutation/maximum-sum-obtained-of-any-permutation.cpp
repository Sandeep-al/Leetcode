class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int MOD = (1e9 + 7);
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (auto& it : requests) {
            prefix[it[0]]++;
            prefix[it[1] + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }

        prefix.pop_back();
        sort(nums.begin(), nums.end());
        sort(prefix.begin(), prefix.end());
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum = (sum + 1LL * nums[i] * prefix[i]) % MOD;
        }

        return sum;
    }
};