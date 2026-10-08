class Solution {
public:
    long long time_taken(vector<int>& piles, int speed) {
        long long total = 0;
        for (auto& it : piles) {
            total += ((it + speed - 1) / speed);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 0;
        int hi = INT_MAX;

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (time_taken(piles, mid) <= h) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};