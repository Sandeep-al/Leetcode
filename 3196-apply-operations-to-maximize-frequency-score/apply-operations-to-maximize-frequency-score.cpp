class Solution {
public:
    long long cost(vector<int>& nums, vector<long long>& prefix, int l, int r) {
        int mid = (l + r) / 2;
        long long median = nums[mid];

        
        long long left_elements = mid - l + 1;
        long long left_sum = prefix[mid] - (l > 0 ? prefix[l - 1] : 0);
        long long left_cost = (left_elements * median) - left_sum;

        
        long long right_elements = r - mid;
        long long right_sum = prefix[r] - prefix[mid];
        long long right_cost = right_sum - (right_elements * median);

        return left_cost + right_cost;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int maxi = 0;
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int r = 0; r < n; r++) {

            while (cost(nums, prefix, l, r) > k) {
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};