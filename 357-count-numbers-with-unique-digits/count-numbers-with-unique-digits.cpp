class Solution {
public:
    int n;

    int solve(int idx, int bitmask) {

        if (idx == n)
            return 0;

        int ans = 0;

        for (int i = 0; i < 10; i++) {

            if (idx == 0 && i == 0)
                continue;

            if (!(bitmask & (1 << i))) {

                ans += 1 + solve(idx + 1, (bitmask | (1 << i)));
            }
        }

        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        this->n = n;
        if (n == 0)
            return 1;

        return solve(0, 0) + 1;
    }
};