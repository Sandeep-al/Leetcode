class Solution {
public:
    int search2(vector<int>& nums, int target, int l, int r) {
        // element<=target
        int n = nums.size();
        int lo = l;
        int hi = r;

        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] <= target) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (lo == l || nums[lo] != target) {
            return -1;
        }
        return lo;
    }
    int search1(vector<int>& nums) {
        int n = nums.size();
        int lo = -1;
        int hi = n;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] >= nums[0])
                lo = mid;
            else
                hi = mid;
        }

        return lo;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = search1(nums);
        int p1 = search2(nums, target, -1, pivot + 1);
        int p2 = search2(nums, target, pivot, n);

        if (p1 == -1)
            return p2;
        return p1;
    }
};