class Solution {
public:
    int m;
    vector<int> dp;
    string yo;
    const int MOD = 1e9 + 7;

    int solve(int i) {
        if (i == m) return 1;
        if (yo[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        long long ans = 0;

        if (yo[i] == '*') {
            ans = (ans + 9LL * solve(i + 1)) % MOD;
        } else {
            ans = (ans + solve(i + 1)) % MOD;
        }

        if (i + 1 < m) {
            if (yo[i] == '*' && yo[i + 1] == '*') {
                ans = (ans + 15LL * solve(i + 2)) % MOD;
            }
            else if (yo[i] == '*') {
                if (yo[i + 1] <= '6') {
                    ans = (ans + 2LL * solve(i + 2)) % MOD;
                } else {
                    ans = (ans + solve(i + 2)) % MOD;
                }
            }
            else if (yo[i + 1] == '*') {
                if (yo[i] == '1') {
                    ans = (ans + 9LL * solve(i + 2)) % MOD;
                } else if (yo[i] == '2') {
                    ans = (ans + 6LL * solve(i + 2)) % MOD;
                }
            }
            else {
                int twoDigit = (yo[i] - '0') * 10 + (yo[i + 1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26) {
                    ans = (ans + solve(i + 2)) % MOD;
                }
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