class Solution {
public:
    int fdays(int capacity, vector<int>& nums) {
        int n = nums.size();
        int days = 1; 
        int curr = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > capacity) {
                return INT_MAX;
            }

            if (curr + nums[i] > capacity) {
                days++;
                curr = nums[i];
            } else {
                curr += nums[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = 0;
        int hi = INT_MAX;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (fdays(mid, weights) <= days) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};