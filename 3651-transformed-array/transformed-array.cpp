class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(), INT_MAX);
        int n=nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            }

            else if (nums[i] > 0) {
                int final_idx=(i+nums[i])%n;
                result[i]=nums[final_idx];
            }

            else{
                int x=abs(nums[i]);
                int final_index = ((i - x) % n + n) % n;
                result[i]=nums[final_index];
            }
        }

        return result;
    }
};