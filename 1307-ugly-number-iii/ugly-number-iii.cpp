class Solution {
public:
    long long count(long long x, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);
        return x / a + x / b + x / c - x / ab - x / ac - x / bc + x / abc;
    }
    int nthMagicalNumber(int n, int a, int b, int c) {
        int lo = 0;
        int hi = INT_MAX;
        while (hi - lo > 1) {
            int mid = ((hi - lo) / 2) + lo;

            if (count(mid, a, b, c) >= n) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        return nthMagicalNumber(n, a, b, c);
    }
};