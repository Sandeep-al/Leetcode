class Solution {
public:
    int bs(int target, vector<int>& nums, int l, int r) {

        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        vector<int> nums = arr;
        int n = arr.size();

        int p1 = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            } else {
                p1 = i;
                break;
            }
        }
        int p2 = 0;
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            } else {
                p2 = i;
                break;
            }
        }

        if(p1==0 && p2==0){
            return 0;
        }
        p1--;
        p2++;
        // now suffix is sorted
        //  i have to find the first element which is >=last element of prefix

        int maxi = 0;
        maxi = max(maxi, p1 + 1);
        maxi = max(maxi, n - p2);
        for (int i = 0; i <= p1; i++) {
            int curr = i + 1;

            int ans = bs(nums[i], nums, p2, n - 1);

            if (ans == -1) {
                continue;
            } else {
                curr += n - ans;
                maxi = max(maxi, curr);
            }
        }

        return n - maxi;
    }
};