class Solution {
public:
    long long solve(int x, vector<int>& nums) {
        // can we make a partition such that every element is less than equal to
        // x

        // calculate cost how many partition it would take to make every element
        // <=x

        // its division
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total+=(nums[i]-1)/x;
        }

        return total;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 0;
        int hi = *max_element(nums.begin(), nums.end()) + 1;

        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;

            if (solve(mid, nums) <= maxOperations) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};