class Solution {
public:
    int mincost(vector<int>& days, vector<int>& costs, int idx, int t, vector<vector<int>>&dp) {

        if (idx == days.size() - 1) {
            if (days[idx] <= t) {
                return 0;
            }

            return min(min(costs[0],costs[1]),costs[2]);
        }
        if(dp[idx][t]!=-1){
            return dp[idx][t];
        }
        if (days[idx] <= t) {
            return mincost(days, costs, idx + 1, t,dp) + 0;
        }
        int a1=0;
        int a2=0;
        int a3=0;
        if (days[idx] > t) {
            a1 = mincost(days, costs, idx + 1, days[idx],dp) + costs[0];
            a2 = mincost(days, costs, idx + 1, days[idx] + 6,dp) + costs[1];
            a3 = mincost(days, costs, idx + 1, days[idx] + 29,dp) + costs[2];
        }

        return dp[idx][t]=min(min(a1, a2), a3);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>>dp(days.size(),vector<int>(1000,-1));
        return mincost(days,costs,0,0,dp);
    }
};