class Solution {
public:
    bool can_we(int capacity, int days, vector<int>& weights) {

        int curr = 0;
        int curr_days = 0;
        for (int i = 0; i < weights.size(); i++) {

            if (curr + weights[i] > capacity) {
                curr_days++;
                curr = 0;
            }

            if (curr + weights[i] <= capacity) {
                curr += weights[i];
            } else {
                return false;
            }
        }

        if(curr){
            curr_days++;
        }

        return curr_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 1e9;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can_we(mid, days, weights)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};