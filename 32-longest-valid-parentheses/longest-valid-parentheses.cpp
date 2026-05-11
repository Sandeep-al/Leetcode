class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                l++;
            if (s[i] == ')')
                r++;
            if (r == l) {
                maxi = max(maxi, l * 2);
            }
            if (r > l) {
                r = 0;
                l = 0;
            }
        }

        l = 0;
        r = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '(')
                l++;
            if (s[i] == ')')
                r++;
            if (r == l) {
                maxi = max(maxi, l * 2);
            }
            if (l > r) {
                r = 0;
                l = 0;
            }
        }
        return maxi;
    }
};