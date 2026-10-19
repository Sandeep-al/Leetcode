class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prev = prefix[i - 1];
            int curr_char = s[i - 1] - 'a';

            int curr = (1 << curr_char) ^ prev;
            prefix[i]=curr;
        }

        vector<bool> ans;

        for (auto& it : queries) {
            int from = it[0];
            int to = it[1];
            int k = it[2];

            int odd_count = __builtin_popcount(prefix[from] ^ prefix[to + 1]);

            if (odd_count / 2 <= k) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};