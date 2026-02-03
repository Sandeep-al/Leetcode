class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)
            return false;

        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i == 0 || i == n - 1)
            return false;

        int peak = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        if (i == peak)
            return false;

        int valley = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i == valley || i != n - 1)
            return false;

        return true;
    }
};