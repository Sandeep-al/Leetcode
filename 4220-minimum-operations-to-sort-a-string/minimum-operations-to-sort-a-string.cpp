class Solution {
public:
    int minOperations(string s) {
        char mini = '{';
        char maxi = '@';
        int n = s.size();
        bool sorted = true;
        for (int i = 0; i < n; i++) {

            char it = s[i];
            if (i > 0 && s[i] < s[i - 1]) {
                sorted = false;
            }
            if (it > maxi) {
                maxi = it;
            }
            if (it < mini) {
                mini = it;
            }
        }

        if (sorted) {
            return 0;
        }
        if (s[0] == mini || s[n - 1] == maxi) {
            return 1;
        }

        if (n == 2) {
            return -1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mini || s[i] == maxi) {
                return 2;
            }
        }

        return 3;
    }
};