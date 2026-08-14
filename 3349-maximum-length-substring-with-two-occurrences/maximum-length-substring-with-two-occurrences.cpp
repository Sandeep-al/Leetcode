class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int n = s.size();
        int maxi = 0;

        vector<int> freq(26, 0);
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;
            while (freq[s[r]-'a'] > 2 && l < r) {
                freq[s[l]-'a']--;
                l++;
            }

            maxi=max(r-l+1,maxi);
        }

        return maxi;
    }
};