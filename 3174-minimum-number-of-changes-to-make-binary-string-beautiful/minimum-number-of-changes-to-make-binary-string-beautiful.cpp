class Solution {
public:
    int minChanges(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); i += 2) {
            int sum = s[i] - '0' + s[i + 1] - '0';
            total += min(sum, 2 - sum);
        }
        return total;
    }
};