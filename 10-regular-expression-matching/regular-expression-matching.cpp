class Solution {
public:
    string s;
    string p;
    int n1;
    int n2;
    bool solve(int idx1, int idx2) {
        if (idx1 == n1 && idx2 == n2) {
            return true;
        }
        if (idx2 == n2) {
            return false;
        }
        if (idx1 == n1) {
            int len = n2 - idx2;
            if (len % 2 == 1) {
                return false;
            }
            for (int i = idx2 + 1; i < n2; i += 2) {
                if (p[i] != '*') {
                    return false;
                }
            }

            return true;
        }
        int ans = 0;
        if (s[idx1] == p[idx2] || p[idx2] == '.') {
            ans = ans || solve(idx1 + 1, idx2 + 1);
        }

        if (idx2 + 1 < n2 && p[idx2 + 1] == '*') {
            char prev = p[idx2];

            ans = ans || solve(idx1, idx2 + 2);

            if (s[idx1] == prev || prev == '.') {
                ans = ans || solve(idx1 + 1, idx2);
            }
        }

        return ans;
    }
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        n1 = s.size();
        n2 = p.size();

        return solve(0, 0);
    }
};
