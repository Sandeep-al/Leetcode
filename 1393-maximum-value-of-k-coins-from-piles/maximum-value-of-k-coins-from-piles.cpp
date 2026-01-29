class Solution {
public:
    int m;
    int solve(vector<vector<int>>& piles, int k, int i,vector<vector<int>>&dp) {
        if(k==0) return 0;
        if (i == m - 1) {
            int yo = 0;
            int size=piles[m - 1].size();
            int range = min(size, k);
            int x = 0;
            while (range--) {
                yo += piles[m - 1][x];
                x++;
            }

            return dp[i][k]= yo;
        }

        if(dp[i][k]!=-1) return dp[i][k];
        vector<int> curr_pile = piles[i];
        int n = curr_pile.size();
        int curr_sum = 0;
        int max_i = INT_MIN;
        int not_take = 0;
        not_take = solve(piles, k, i + 1,dp);
        int range = min(k, n);
        for (int x = 0; x < range; x++) {
            curr_sum += curr_pile[x];
            max_i = max(max_i, curr_sum + solve(piles, k - x - 1, i + 1,dp));
        }

        return dp[i][k]= max(max_i, not_take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        m = piles.size();
        vector<vector<int>>dp(m+1,vector<int>(k+1,-1));
        return solve(piles, k, 0,dp);
    }
};