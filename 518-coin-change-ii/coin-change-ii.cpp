class Solution {
public:
    int move(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if (amount == 0) {
            return 1;
        }
        if (idx == -1) {
            return 0;
        }

        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int notake = move(idx - 1, amount, coins, dp);
        
        int take = 0;
        if (coins[idx] <= amount) {
            take = move(idx, amount - coins[idx], coins, dp);
        }
       

        return dp[idx][amount] = take+notake;
    }
    int change(int amount, vector<int>& coins) {


        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int x = move(n - 1, amount, coins, dp);

        

        return x;

    }
};