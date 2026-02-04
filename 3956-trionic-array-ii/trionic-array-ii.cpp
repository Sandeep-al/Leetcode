class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        // --- Initialization (Base Case: i = n-1) ---
        // These variables represent the state at index (i + 1)
        long long trend0 = LLONG_MIN;
        long long trend1 = LLONG_MIN;
        long long trend2 = LLONG_MIN;
        long long trend3 = nums[n - 1]; // Only valid state at the very end

        // --- Backwards Loop (i = n-2 down to 0) ---
        for (int i = n - 2; i >= 0; i--) {
            
            // Temporary variables for the current index 'i'
            long long curr_trend0 = LLONG_MIN;
            long long curr_trend1 = LLONG_MIN;
            long long curr_trend2 = LLONG_MIN;
            long long curr_trend3 = LLONG_MIN;

            int curr_val = nums[i];
            int next_val = nums[i + 1];

            // --- Trend 0 (Start) ---
            // Option 1: Skip this element
            curr_trend0 = trend0; 
            // Option 2: Start Trend 1 (Increasing)
            if (next_val > curr_val && trend1 != LLONG_MIN) 
                 curr_trend0 = max(curr_trend0, curr_val + trend1);

            // --- Trend 1 (Increasing leg) ---
            // Option 1: Continue Increasing
            if (next_val > curr_val && trend1 != LLONG_MIN)
                 curr_trend1 = max(curr_trend1, curr_val + trend1);
            // Option 2: Switch to Trend 2 (Decreasing)
            else if (next_val < curr_val && trend2 != LLONG_MIN)
                 curr_trend1 = max(curr_trend1, curr_val + trend2); 

            // --- Trend 2 (Decreasing leg) ---
            // Option 1: Continue Decreasing
            if (next_val < curr_val && trend2 != LLONG_MIN)
                 curr_trend2 = max(curr_trend2, curr_val + trend2);
            // Option 2: Switch to Trend 3 (Final Increasing)
            if (next_val > curr_val && trend3 != LLONG_MIN)
                 curr_trend2 = max(curr_trend2, curr_val + trend3); 

            // --- Trend 3 (Final Increasing leg) ---
            // Option 1: Stop here (End of array sequence)
            curr_trend3 = curr_val; 
            // Option 2: Continue Increasing
            if (next_val > curr_val && trend3 != LLONG_MIN)
                 curr_trend3 = max(curr_trend3, curr_val + trend3);

            // --- Shift Window: Current values become "next" for the upcoming loop ---
            trend0 = curr_trend0;
            trend1 = curr_trend1;
            trend2 = curr_trend2;
            trend3 = curr_trend3;
        }

        return trend0; // The answer for starting at index 0 in state 0
    }
};