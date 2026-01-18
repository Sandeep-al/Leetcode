class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        for (int i = 0; i < n; i++)
            hash[i] = i;
        int maxi = 1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) &&
                    (dp[j] + 1 > dp[i])) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> subset;
        subset.push_back(nums[last]);

        while (hash[last] != last) {
            last = hash[last];
            subset.push_back(nums[last]);
        }

        reverse(subset.begin(), subset.end());

        return subset;
    }
};