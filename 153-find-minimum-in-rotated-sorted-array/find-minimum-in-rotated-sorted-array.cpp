class Solution {
public:
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
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int pivot=search1(nums);
        if(pivot==n-1) return nums[0];
        return nums[pivot+1];
    }
};