class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm

        int element = nums[0];
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            if (count == 0) {
                element = nums[i];
                count = 1;
            } else {
                if (nums[i] != element) {
                    count--;
                } else {
                    count++;
                }
            }
        }

        return element;
    }
};