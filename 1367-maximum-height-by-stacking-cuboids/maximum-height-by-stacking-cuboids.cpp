class Solution {
public:
    vector<vector<int>> arr;
    int n;
    vector<vector<int>> dp;

    int solve(int idx, int prev_idx) {
        if (idx >= n)
            return 0;

        if (dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];

        int notTake = solve(idx + 1, prev_idx);
        
        int take = 0;
        if (prev_idx == -1 || (arr[idx][0] >= arr[prev_idx][0] && 
                               arr[idx][1] >= arr[prev_idx][1] && 
                               arr[idx][2] >= arr[prev_idx][2])) {
            take = arr[idx][2] + solve(idx + 1, idx);
        }

        return dp[idx][prev_idx + 1] = max(take, notTake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        
        sort(cuboids.begin(), cuboids.end());

        arr = cuboids;
        n = cuboids.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, -1);
    }
};