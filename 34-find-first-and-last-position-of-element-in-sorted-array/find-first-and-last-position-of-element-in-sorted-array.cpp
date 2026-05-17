class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mini = -1;
        int maxi = -1;

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                mini = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = 0;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                maxi = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {mini, maxi};
    }
};