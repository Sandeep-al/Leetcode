class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // minimum is in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // minimum can be mid or left half
            else if (nums[mid] < nums[high]) {
                high = mid;
            }

            // duplicates case
            else {
                high--;
            }
        }

        return nums[low];
    }
};