class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int h = nums.size() - 1;

        int ans = INT_MAX;

        while(l <= h) {

            int mid = l + (h - l) / 2;
            if(nums[mid]==nums[l] && nums[h]==nums[mid]){
                ans=min(ans,nums[mid]);
                l++;
                h--;
            }
            // left half sorted
            else if(nums[l] <= nums[mid]) {

                ans = min(ans, nums[l]);

                l = mid + 1;
            }

            // right half sorted
            else {

                ans = min(ans, nums[mid]);

                h = mid - 1;
            }
        }

        return ans;
    }
};