class Solution {
public:
    bool isGood(int num) {
        if (num == 0) return false;

        bool changed = false;

        while (num > 0) {
            int d = num % 10;

            // invalid digits
            if (d == 3 || d == 4 || d == 7) return false;

            // digits that change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;

            num /= 10;
        }

        return changed;
    }

    int solve(int i, int n) {
        if (i > n) return 0;

        int count = 0;
        if (isGood(i)) count = 1;

        return count + solve(i + 1, n);
    }

    int rotatedDigits(int n) {
        return solve(1, n);
    }
};