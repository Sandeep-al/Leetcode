class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int x = sum % 9;
        int y = sum / 9;
        string ans = "";
        for (int i = 0; i < y; i++) {
            ans.push_back('9');
        }

        if (x != 0) {
            ans.push_back(x + '0');
        }

        int curr = ans.size();
        for (int i = 0; i < num - curr; i++) {
            ans.push_back('0');
        }
        if (ans.size() != num) {
            return "";
        }
        return ans;
    }
};