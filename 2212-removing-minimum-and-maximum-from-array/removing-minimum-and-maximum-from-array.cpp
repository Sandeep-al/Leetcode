class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1 = 0;
        int idx2 = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                idx1 = i;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
                idx2 = i;
            }
        }

        int option1 = max(idx1, idx2) + 1;
        int option2 = nums.size() - min(idx1, idx2);
        int option3 = min(idx1, idx2) + 1 + nums.size() - max(idx1, idx2);
        return min({option1, option2, option3});
    }
};