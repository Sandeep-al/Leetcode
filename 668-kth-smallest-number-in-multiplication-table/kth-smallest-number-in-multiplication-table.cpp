class Solution {
public:
    int count(int x, int m, int n) {
        int total = 0;

        for (int i = 1; i <= m; i++) {
            total += min(x / i, n);
        }

        return total;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 0;
        int hi = INT_MAX;

        while (hi - lo > 1) {
            int mid = (hi - lo) / 2 + lo;

            if (count(mid, m, n) >= k) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};