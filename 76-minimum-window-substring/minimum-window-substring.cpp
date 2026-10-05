class Solution {
public:
    int idx(char c) {
        if (c >= 'a' && c <= 'z')
            return c - 'a';
        return c - 'A' + 26;
    }

    bool it_is_valid(const vector<int>& freq, const vector<int>& target) {
        for (int i = 0; i < 52; i++) {
            if (freq[i] < target[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> freq(52, 0);
        vector<int> target(52, 0);

        int l = 0;
        int n = s.size();

        for (int i = 0; i < t.size(); i++) {
            target[idx(t[i])]++;
        }

        int mini = INT_MAX;
        int start = -1;

        for (int r = 0; r < n; r++) {
            freq[idx(s[r])]++;

            while (it_is_valid(freq, target)) {
                if (r - l + 1 < mini) {
                    start = l;
                    mini = r - l + 1;
                }
                freq[idx(s[l])]--;
                l++;
            }
        }
        if (mini == INT_MAX) {
            return "";
        }
        return s.substr(start, mini);
    }
};
