class Solution {
public:
    int m, n;
    vector<int> all_mask; 
    vector<int> broken;   
    vector<vector<int>> dp;

    int solve(int idx, int prev) {
        if (idx == m)
            return 0;
        if (dp[idx][prev] != -1)
            return dp[idx][prev];

        int best = 0;
        for (int i = 0; i < (int)all_mask.size(); i++) {
            int curr = all_mask[i];

            if (curr & broken[idx])
                continue;

            if ((curr & (prev << 1)) || (curr & (prev >> 1)))
                continue;

            best = max(best, __builtin_popcount(curr) + solve(idx + 1, curr));
        }
        return dp[idx][prev] = best;
    }

    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size();
        n = seats[0].size();

        for (int mask = 0; mask < (1 << n); mask++) {
            if ((mask & (mask >> 1)) == 0)
                all_mask.push_back(mask);
        }

        broken.assign(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (seats[i][j] == '#')
                    broken[i] |= (1 << j);

        dp.assign(m, vector<int>(1 << n, -1));
        return solve(0, 0);
    }
};