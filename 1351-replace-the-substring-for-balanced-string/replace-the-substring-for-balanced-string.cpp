class Solution {
public:
    int n;
    int it_is_valid(vector<int>& freq, vector<int>& total) {
        for (int i = 0; i < 4; i++) {
            if (freq[i] < (total[i] - (n / 4))) {
                return false;
            }
        }

        return true;
    }
    int idx(char c) {
        if (c == 'Q') {
            return 0;
        } else if (c == 'W') {
            return 1;
        } else if (c == 'E') {
            return 2;
        } else {
            return 3;
        }
    }
    int balancedString(string s) {
        n = s.size();
        vector<int> total(4, 0);
        for (int i = 0; i < s.size(); i++) {
            total[idx(s[i])]++;
        }
        bool balanced = true;
        for (int i = 0; i < 4; i++)
            if (total[i] != n / 4)
                balanced = false;
        if (balanced)
            return 0;
        vector<int> freq(4, 0);
        int l = 0;
        int mini = n;

        for (int r = 0; r < n; r++) {
            freq[idx(s[r])]++;

            while (it_is_valid(freq, total) && l <= r) {
                mini = min(mini, r - l + 1);
                freq[idx(s[l])]--;
                l++;
            }
        }

        return mini;
    }
};