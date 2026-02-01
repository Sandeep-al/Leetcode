class Solution {
public:
    int len;
    vector<pair<int, int>> precount;
    vector<string> str;
    int m1;
    int n1;
    vector<vector<vector<int>>> dp;
    int solve(int m, int n, int i) {

        if (m > m1 || n > n1) {
            return 0;
        }

        if (i == len)
            return 0;

        if (dp[m][n][i] != -1) {
            return dp[m][n][i];
        }
        // take;

        int ones = precount[i].first;
        int zeroes = precount[i].second;

        int temp_ones = ones + m;
        int temp_zeroes = zeroes + n;
        int take = INT_MIN;
        if (temp_ones <= m1 && temp_zeroes <= n1) {
            take = 1 + solve(temp_ones, temp_zeroes, i + 1);
        }

        int nottake = solve(m, n, i + 1);

        return dp[m][n][i] = max(take, nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        len = strs.size();
        int one = 0;
        int zero = 0;
        m1 = n;
        n1 = m;

        dp.assign(m1 + 1,
                  vector<vector<int>>(n1 + 1, vector<int>(len + 1, -1)));
        precount.assign(len, pair<int, int>());
        int i = 0;
        for (auto& it : strs) {
            for (auto& jt : it) {
                if (jt == '1')
                    one++;
                else
                    zero++;
            }

            precount[i].first = one;
            precount[i].second = zero;
            one = 0;
            zero = 0;
            i++;
        }

        str = strs;

        return solve(0, 0, 0);
    }
};