class Solution {
public:
    long long number_of_trips(vector<int>& nums, long long max_time) {

        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += (max_time / nums[i]);
        }
        
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 0;
        long long hi = totalTrips*1LL*(*max_element(time.begin(),time.end())+1);

        while (hi - lo > 1) {
            long long mid = lo + (hi - lo) / 2;

            if (number_of_trips(time, mid) >= totalTrips) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};