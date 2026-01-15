class Solution {
public:
    int move(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if(amount==0){
            return 0;
        }
        if (idx == -1 ) {
            return INT_MAX;
        }

        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int notake = move(idx - 1, amount, coins, dp);
        int sub = INT_MAX;
        int take = INT_MAX;
        if (coins[idx] <= amount) {
            sub = move(idx, amount - coins[idx], coins, dp);
        }
        if (sub != INT_MAX) {
            take = 1 + sub;
        }

        return dp[idx][amount] = min(take, notake);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int x = move(n - 1, amount, coins, dp);

        if (x == INT_MAX) {
            return -1;
        }

        return x;
    }
};

// class Solution {
// public:
//     int findmin(vector<int>& coins, int idx, int amount,
//                 vector<vector<int>>& dp) {

//         if (0 == amount)
//             return 0;
//         if (0 > amount || idx == -1)
//             return INT_MAX;
//         if (dp[idx][amount] != -1)
//             return dp[idx][amount];
//         int take = INT_MAX;
//         int sub = findmin(coins, idx, amount - coins[idx], dp);
//         if (sub != INT_MAX) {
//             take = 1 + sub;
//         }
//         int nottake = findmin(coins, idx - 1, amount, dp);

//         return dp[idx][amount] = min(take, nottake);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size() + 1,
//                                vector<int>(amount + 1, -1));
//         int y = findmin(coins, coins.size() - 1, amount, dp);
//         if (y == INT_MAX)
//             return -1;
//         return y;
//     }
// };