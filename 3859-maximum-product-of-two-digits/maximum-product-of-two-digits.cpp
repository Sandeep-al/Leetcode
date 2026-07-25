class Solution {
public:
    int maxProduct(int n) {
        int maxi = -1;
        int maxi_idx = -1;
        vector<int> nums;
        int x = n;
        while (x) {
            nums.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxi_idx = i;
            }
        }
        int maxi_2 = -1;
        int maxi_2_idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi_2 && maxi_idx != i) {
                maxi_2 = nums[i];
            }
        }

        return maxi * maxi_2;
    }
};