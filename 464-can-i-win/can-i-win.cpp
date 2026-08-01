class Solution {
public:
    int maxChoosableInteger;
    int desiredTotal;
    vector<int> dp;

    bool solve(int curr_mask, int curr_sum) {

        if (dp[curr_mask] != -1)
            return dp[curr_mask];

        for (int i = 1; i <= maxChoosableInteger; i++) {

            if ((curr_mask & (1 << i)) == 0) {

               
                if (curr_sum + i >= desiredTotal) {
                    return dp[curr_mask] = true;
                }

                int new_mask = curr_mask | (1 << i);

               
                if (solve(new_mask, curr_sum + i) == false) {
                    return dp[curr_mask] = true;
                }
            }
        }

        return dp[curr_mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        this->maxChoosableInteger = maxChoosableInteger;
        this->desiredTotal = desiredTotal;

        if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 <
            desiredTotal)
            return false;

        dp.assign(1 << (maxChoosableInteger + 1), -1);

        return solve(0, 0);
    }
};