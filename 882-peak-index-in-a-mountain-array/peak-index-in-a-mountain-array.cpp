class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {


        int n = nums.size();
        int high = n-1;
        int low = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int left = (mid == 0) ? -1 : nums[mid - 1];
            int right = (mid == n-1) ? -1 : nums[mid + 1];

            if (nums[mid] > left &&
                nums[mid] < right) { // positive slope go right
                low = mid + 1;
            } else if (nums[mid] < left && nums[mid] > right) { // negative
                                                                // slope
                high = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};