class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeroes = 0;
        int twos = n - 1;

        int i = 0;

        while (i <= twos) {
            if (nums[i] == 0) {
                swap(nums[i], nums[zeroes]);
                zeroes++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[twos]);
                twos--;
            }
            else{
                i++;
            }
            
            
            
            
        }
    }
};