class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int v : nums)
            total += v;
        int target = total - x;
        if (target < 0)
            return -1;

        int n = nums.size(), l = 0, sum = 0, best = -1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target && l <= r) 
                sum -= nums[l++];
            if (sum == target) 
                best = max(best, r - l + 1);
        }
        return best == -1 ? -1 : n - best;
    }
};