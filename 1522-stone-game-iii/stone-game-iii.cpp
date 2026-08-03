class Solution {
public:
    vector<int> nums;

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        nums = stoneValue;

        int a = 0;
        int b = 0;
        int c = 0;

        for (int i = n - 1; i >= 0; i--) {
            int maxi = INT_MIN;
            int curr_score = 0;

            curr_score += nums[i];
            maxi = max(maxi, curr_score - a);

            if (i + 1 < n) {
                curr_score += nums[i + 1];
                maxi = max(maxi, curr_score - b);
            }
            if (i + 2 < n) {
                curr_score += nums[i + 2];
                maxi = max(maxi, curr_score - c);
            }

            c = b;
            b = a;
            a = maxi;
        }

        if (a > 0) {
            return "Alice";
        } else if (a < 0) {
            return "Bob";
        }

        return "Tie";
    }
};