class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int max_jump = 0;

        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (i % 2 != 0 && i != n - 1) {
                continue;
            }

            max_jump = max(max_jump, abs(stones[i] - stones[prev]));
            prev = i;
        }

        prev = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0 && i != 0) {
                continue;
            }

            max_jump = max(max_jump, abs(stones[i] - stones[prev]));
            prev = i;
        }

        return max_jump;
    }
};