class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr_avg = 0;
        double curr_sum = 0;
        int n=nums.size();

        int x = k;

        int i = 0;
        while (i < nums.size() && x > 0) {
            x--;
            curr_sum += nums[i];
            i++;
        }

        curr_avg = curr_sum / (double)k;
        int j = 0;
        for (; i < n; i++) {
            curr_sum -= nums[j];
            j++;

            curr_sum += nums[i];
            

            curr_avg = max(curr_avg, curr_sum / (double)k);
        }

        return curr_avg;
    }
};