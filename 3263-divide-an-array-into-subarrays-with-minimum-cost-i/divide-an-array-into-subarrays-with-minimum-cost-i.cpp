class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n1 = nums[0];
        int n2 = INT_MAX;
        int n3 = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < n2) {
                n3 = n2;
                n2 = nums[i];
            } else if (nums[i] < n3) {
                n3 = nums[i];
            }
        }

        return n1 + n2 + n3;
    }
};