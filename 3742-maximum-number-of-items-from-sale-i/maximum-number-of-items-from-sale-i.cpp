class Solution {
public:
    int n;
    int dp[1001][1501][2];
    int solve(int idx, int budget, int bought, vector<vector<int>>& items,
              vector<int>& free) {

        if (idx == n) {
            return 0;
        }
        if (dp[idx][budget][bought] != -1) {
            return dp[idx][budget][bought];
        }
        int cost = items[idx][1];
        int maxi = 0;

        int option1 = solve(idx + 1, budget, 0, items, free);
        maxi = max(maxi, option1);
        if (bought == 0) {
            if (cost <= budget) {
                int option2 =
                    1 + free[idx] + solve(idx, budget - cost, 1, items, free);

                maxi = max(maxi, option2);
            }
        } else {
            if (cost <= budget) {
                int option3 = 1 + solve(idx, budget - cost, 1, items, free);

                maxi = max(maxi, option3);
            }
        }

        return dp[idx][budget][bought] = maxi;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> arr(1000, 0);
        n = items.size();

        for (int i = 0; i < items.size(); i++) {
            for (int j = 0; j < items.size(); j++) {
                if (i != j) {
                    if ((items[j][0] % items[i][0]) == 0) {
                        arr[i]++;
                    }
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, budget, 0, items, arr);
    }
};