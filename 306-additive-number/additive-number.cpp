class Solution {
public:
    int prev1 = -1;
    int prev2 = -1;
    string nums;
    int n;
    bool solve(int idx, int count, long long prev1, long long prev2) {
        if (idx == n) {
            if (count >= 3) {
                return true;
            }

            return false;
        }

        if (nums[idx] == '0') {

            if (prev1 == -1 || prev2 == -1 || prev1 + prev2 == 0) {

                if (solve(idx + 1, count + 1, prev2, 0)) {
                    return true;
                };
            }
        } else {
            long long curr = 0;
            for (int i = idx; i < n; i++) {

                int digit = nums[i] - '0';

                if (curr > (LLONG_MAX - digit) / 10)
                    break;

                curr = curr * 10 + digit;
                if (prev1 == -1 || prev2 == -1 || 1LL*prev1 + 1LL*prev2 == curr) {

                    if (solve(i + 1, count + 1, prev2, curr)) {
                        return true;
                    }
                }
            }
        }

        return false;

        // means its first or second number no need to check additive
    }
    bool isAdditiveNumber(string num) {
        nums = num;
        n = nums.size();
        return solve(0, 0, -1, -1);
    }
};