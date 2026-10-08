class Solution {
public:
    int search1(vector<int>& nums, int target) {
        // invariant is element>=target

        int n = nums.size();
        int lo = -1;
        int hi = n;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid;
        }

        if (hi == n || nums[hi] != target) {
            return -1;
        }

        return hi;
    }
    int search2(vector<int>& nums, int target) {
        // invariant is element<=target

        int n = nums.size();
        int lo = -1;
        int hi = n;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid;
            else
                hi = mid;
        }

        if (lo == -1 || nums[lo] != target) {
            return -1;
        }

        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search1(nums, target), search2(nums, target)};
    }
};