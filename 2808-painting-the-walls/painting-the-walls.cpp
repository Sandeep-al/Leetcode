class Solution {
public:
    int n;
    vector<int> cost;
    vector<int> time;
    int dp[501][501];
    int solve(int idx, int remaining_walls) {

        if (remaining_walls <= 0) {
            return 0;
        }

        if (idx == n) {
            return INT_MAX;
        }

        if (dp[idx][remaining_walls] != -1) {
            return dp[idx][remaining_walls];
        }
        // make it paint with paid painter

        int option1 = solve(idx + 1, remaining_walls - 1 - time[idx]);
        if (option1 != INT_MAX) {
            option1 += cost[idx];
        }

        // dont paint it with this painter ...later free painter will do it
        int option2 = solve(idx + 1, remaining_walls);

        return dp[idx][remaining_walls] = min(option1, option2);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {

        n = cost.size();
        this->cost = cost;
        this->time = time;
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};