class Solution {
public:
    string solve(int idx, string& target, vector<int>& freq) {

        int n = target.size();

        if (idx == n)
            return "#";

        int x = target[idx] - 'a';

        if (freq[x] > 0) {

            freq[x]--;

            string res = solve(idx + 1, target, freq);

            if (res != "#")
                return target[idx] + res;

            freq[x]++;
        }

        for (int c = x + 1; c < 26; c++) {

            if (freq[c] > 0) {

                freq[c]--;

                string res;
                res += char('a' + c);

                for (int j = 0; j < 26; j++) {
                    while (freq[j] > 0) {
                        res += char('a' + j);
                        freq[j]--;
                    }
                }

                return res;
            }
        }

        return "#";
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = solve(0, target, freq);

        return ans == "#" ? "" : ans;
    }
};