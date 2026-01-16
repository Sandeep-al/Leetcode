class Solution {
public:
    int move(vector<int>& prices, int canbuy, int idx, int cap,
             vector<vector<vector<int>>>& dp) {

        if (idx == prices.size()) {
            return 0;
        }

        if (cap == 0) {
            return 0;
        }

        if (dp[idx][canbuy][cap] != -1) {
            return dp[idx][canbuy][cap];
        }

        if (canbuy) {

            int buy = -prices[idx] + move(prices, 0, idx + 1, cap, dp);

            int dontbuy = 0 + move(prices, 1, idx + 1, cap, dp);

            return dp[idx][canbuy][cap] = max(buy, dontbuy);
        } else {

            int sell = prices[idx] + move(prices, 1, idx + 1, cap - 1, dp);

            int dontsell = 0 + move(prices, 0, idx + 1, cap, dp);

            return dp[idx][canbuy][cap] = max(sell, dontsell);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return move(prices, 1, 0, k, dp);
    }
};