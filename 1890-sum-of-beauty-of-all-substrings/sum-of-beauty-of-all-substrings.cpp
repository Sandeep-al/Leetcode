class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int count[26] = {0};

            for (int j = i; j < n; j++) {
                count[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (count[k] > 0) {
                        maxi = max(maxi, count[k]);
                        mini = min(mini, count[k]);
                    }
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};