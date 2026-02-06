class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int maxi = 1;
        for (int i = 0; i < nums.size() - 1; i++) {

            int j = i;
            long long target = (long long)nums[i] * k;

            int start = i + 1;
            int end = nums.size() - 1;

            while (start <= end) {

                int mid = (end - start) / 2 + start;

                if (nums[mid] <= target) {
                    j = mid;
                    start = mid + 1;
                } else if (nums[mid] > target) {
                    end = mid - 1;
                }
            }

            maxi = max(maxi, j - i + 1);
        }

        return n- maxi;
    }
};