class Solution {
public:
    vector<int> points;
    vector<int> dp;
    int mx;

    int solve(int i) {
        if (i > mx)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int nottake = solve(i + 1);

        int take = points[i] + solve(i + 2);

        return dp[i] = max(take, nottake);
    }

    int deleteAndEarn(vector<int>& nums) {
        mx = *max_element(nums.begin(), nums.end());
        points.assign(mx + 1, 0);

        for (int x : nums)
            points[x] += x;

        dp.assign(mx + 2, -1);
        return solve(0);
    }
};
