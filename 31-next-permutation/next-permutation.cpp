class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int pivot = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        int to_swap = -1;
        if (pivot != -1) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    to_swap = i;
                    break;
                }
            }
        }

        if (pivot != -1 && to_swap != -1) {
            swap(nums[pivot], nums[to_swap]);
        }
        int j = n - 1;
        to_swap = pivot + 1;
        while (to_swap <= j) {
            swap(nums[to_swap], nums[j]);
            to_swap++;
            j--;
        }
    }
};