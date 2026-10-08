class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int score = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                score++;
            } else {
                score--;
            }
            if (!((score == 1 && s[i] == '(') || (score == 0 && s[i] == ')'))) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};