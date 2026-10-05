class Solution {
public:
    int scoreOfParentheses(string s) {
        int total = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                total++;
                if (s[i + 1] == ')') {
                    ans += (1 << total - 1);
                }
            }
            else{
                total--;
            }
        }

        return ans;
    }
};