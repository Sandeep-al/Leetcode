class Solution {
public:
    char shift(char x, long long amount) {

        int netShift = amount % 26;
        int newPos = (x - 'a' + netShift + 26) % 26;
        return 'a' + newPos;
    }
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.size();
        vector<long long> diff(n + 1, 0);
        int r = -1;
        for (auto& it : shifts) {

            r++;

            diff[0] += it;
            diff[r + 1] -= it;
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