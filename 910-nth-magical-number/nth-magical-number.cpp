class Solution {
public:
    long long count(long long x, int a, int b) {

        long long total = 0;
        total += x / a;
        total += x / b;
        total -= (x / lcm(a,b));

        return total;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long lo = 0;
        long long hi = LONG_MAX;
        while (hi - lo > 1) {
            long long mid = ((hi - lo) / 2) + lo;

            if (count(mid, a, b) >= n) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        long long yo=1e9+7;
        return hi % (yo);
    }
};