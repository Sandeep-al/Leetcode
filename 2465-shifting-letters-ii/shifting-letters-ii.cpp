class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        string ans;
        for (auto& it : shifts) {
            int l = it[0];
            int r = it[1];
            int x = (it[2] == 1) ? 1 : -1;

            diff[l] += x;
            diff[r + 1] -= x;
        }

        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int curr = ((diff[i] % 26) + 26) % 26;
            int c = ((((s[i] - 'a') + curr) % 26) + 26) % 26;
            ans.push_back(c + 'a');
        }

        return ans;
    }
};