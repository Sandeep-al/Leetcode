class Solution {
public:
    int maxPower(string s) {
        int maxi = 1;
        int curr = 1;

        int n = s.size();

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        maxi = max(maxi, curr);

        return maxi;
    }
};