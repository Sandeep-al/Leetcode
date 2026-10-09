class Solution {
public:
    int result(int divisor, vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {

            total += ((divisor + nums[i] - 1) / divisor);
        }

        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int lo = 0;
        int hi = INT_MAX;

        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;
            if (result(mid, nums) <= threshold) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};