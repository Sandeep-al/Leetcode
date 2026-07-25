class Solution {
public:
    char shift(char x, int amount) {

        int netShift = amount % 26;
        int newPos = (x - 'a' + netShift + 26) % 26;
        return 'a' + newPos;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (auto& it : shifts) {
            int l = it[0];
            int r = it[1];
            int direction = (it[2] == 0) ? -1 : 1;

            diff[l] += direction;
            diff[r + 1] -= direction;
        }

        for (int i = 1; i < n + 1; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            s[i] = shift(s[i], diff[i]);
        }

        return s;
    }
};