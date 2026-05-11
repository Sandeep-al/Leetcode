class Solution {
public:
    string s;
    int n;

    vector<int> dp;

    int solve(int i) {

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = 0;

        if (s[i] == '(') {

            if (i + 1 < n && s[i + 1] == ')') {

                ans = 2 + solve(i + 2);
            }

            else if (i + 1 < n) {

                int inside_len = solve(i + 1);

                int matching_index = i + inside_len + 1;

                if (matching_index < n && s[matching_index] == ')') {

                    ans = inside_len + 2;

                    ans += solve(matching_index + 1);
                }
            }
        }

        return dp[i] = ans;
    }

    int longestValidParentheses(string str) {

        s = str;

        n = s.size();

        dp.assign(n, -1);

        int final_ans = 0;

        for (int i = 0; i < n; i++) {

            final_ans = max(final_ans, solve(i));
        }

        return final_ans;
    }
};