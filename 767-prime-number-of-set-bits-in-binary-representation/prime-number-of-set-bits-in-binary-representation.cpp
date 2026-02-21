class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int n = left; n <= right; n++) {
            int c = __builtin_popcount(n);
            if (c == 2 || c == 3 || c == 5 || c == 7 || c == 11 || c == 13 ||
                c == 17 || c == 19) {
                count++;
            }
        }
        return count;
    }
};