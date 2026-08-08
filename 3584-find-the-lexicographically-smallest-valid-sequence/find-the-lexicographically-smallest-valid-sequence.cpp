class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (dp[i + 1] < m &&
                word1[i] == word2[m - dp[i + 1] - 1]) {
                dp[i]++;
            }
        }

        vector<int> ans;
        int j = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                if (mismatchUsed) {
                    if (dp[i + 1] < m - j - 1)
                        continue;
                }

                ans.push_back(i);
                j++;
            }
            else if (!mismatchUsed) {
                if (dp[i + 1] >= m - j - 1) {
                    ans.push_back(i);
                    mismatchUsed = true;
                    j++;
                }
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};