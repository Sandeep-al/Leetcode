class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.length() < b.length();
});
        unordered_map<string, int>dp; 
        int maxi = 1;

        for (string word : words) {
            dp[word] = 1;

            for (int i = 0; i < word.length(); i++) {

                string prev = word.substr(0, i) + word.substr(i + 1);

                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[word]);
        }

        return maxi;
    }
};