class Solution {
public:
    int f;
    int move(vector<int>& prices, int canbuy, int idx,vector<vector<int>>&dp) {
        
        if (idx == prices.size()) {
            return 0;
        }
        if(dp[idx][canbuy]!=-1){
            return dp[idx][canbuy];
        }
        if (canbuy) {

            int buy = -prices[idx]-f + move(prices, 0, idx + 1,dp);

            int dontbuy = 0 + move(prices, 1, idx + 1,dp);

            return dp[idx][canbuy]=max(buy, dontbuy);
        } else {

            int sell = prices[idx] + move(prices,1,idx+1,dp);

            int dontsell = 0 + move(prices, 0, idx + 1,dp);

            return dp[idx][canbuy]=max(sell, dontsell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        f=fee;
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return move(prices, 1, 0,dp); 
    }
};