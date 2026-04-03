class Solution {
public:
    vector<vector<int>> coins;
    int m;
    int n;
    vector<vector<vector<int>>>dp;
    int solve(int i, int j, int neutralization_points) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return INT_MIN;
        }
        if(dp[i][j][neutralization_points]!=INT_MAX){
            return dp[i][j][neutralization_points];
        }

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0)
                return coins[i][j];
            if (neutralization_points > 0)
                return 0;
            return coins[i][j];
        }

        // positive value
        int coins_gained = INT_MIN;
        if (coins[i][j] >= 0) {
            int solve1 = solve(i + 1, j, neutralization_points);
            int solve2 = solve(i, j + 1, neutralization_points);

            if (solve1 != INT_MIN) {
                coins_gained = max(coins_gained, solve1 + coins[i][j]);
            }
            if (solve2 != INT_MIN) {
                coins_gained = max(coins_gained, solve2 + coins[i][j]);
            }
        } else {
            // use neutralization points

            if (neutralization_points > 0) {
                int solve1 = solve(i + 1, j, neutralization_points - 1);
                int solve2 = solve(i, j + 1, neutralization_points - 1);

                if (solve1 != INT_MIN) {
                    coins_gained = max(coins_gained, solve1);
                }
                if (solve2 != INT_MIN) {
                    coins_gained = max(coins_gained, solve2);
                }
            }

            // normal reduction
            int solve11 = solve(i + 1, j, neutralization_points);
            int solve22 = solve(i, j + 1, neutralization_points);

            if (solve11 != INT_MIN) {
                coins_gained = max(coins_gained, solve11 - abs(coins[i][j]));
            }
            if (solve22 != INT_MIN) {
                coins_gained = max(coins_gained, solve22 - abs(coins[i][j]));
            }
        }

        return dp[i][j][neutralization_points]=coins_gained;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        this->coins=coins;
        m=coins.size();
        n=coins[0].size();
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(4,INT_MAX)));
        
        return solve(0,0,2);
    }
};