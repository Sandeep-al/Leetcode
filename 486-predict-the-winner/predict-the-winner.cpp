class Solution {
public:
    int n;
    vector<int> nums;

    int score(int idx1, int idx2, int parity) {
        if (idx1 > idx2)
            return 0;

        if (parity == 0) {
            int left = nums[idx1] + score(idx1 + 1, idx2, 1);
            int right = nums[idx2] + score(idx1, idx2 - 1, 1);

            return max(left, right);
        }
        else {
            int left = score(idx1 + 1, idx2, 0);
            int right = score(idx1, idx2 - 1, 0);

            return min(left, right);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        int total = 0;

        for (int x : nums)
            total += x;

        int player0Score = score(0, n - 1, 0);

        return player0Score >= total - player0Score;
    }
};