class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            int sum = a + b;

            // initially 2 moves for all

            diff[2] += 2;

            // 1 move zone starts
            diff[low] -= 1;

            // exact sum -> 0 moves
            diff[sum] -= 1;

            // after exact sum back to 1 move
            diff[sum + 1] += 1;

            // after high back to 2 moves
            diff[high + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;

        for (int target = 2; target <= 2 * limit; target++) {

            cur += diff[target];

            ans = min(ans, cur);
        }

        return ans;
    }
};