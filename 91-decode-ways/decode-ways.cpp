class Solution {
public:
    int m;
    vector<int> dp;
    string yo;

    int solve(int i) {
        if (i == m)
            return 1;
        if (yo[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ans = 0;

        // 1 digit
        ans += solve(i + 1);

        // 2 digit
        if (i + 1 < m) {
            int num = (yo[i] - '0') * 10 + (yo[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                ans += solve(i + 2);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        m = s.size();
        yo = s;
        dp.assign(m, -1);
        return solve(0);
    }
};
