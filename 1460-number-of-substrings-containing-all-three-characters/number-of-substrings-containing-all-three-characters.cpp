class Solution {
public:
    int valid(vector<int>& freq) {
        for (int i = 0; i < 3; i++) {
            if (freq[i] < 1) {
                return 0;
            }
        }

        return 1;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int count = 0;
        vector<int> freq(3, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;

            while (valid(freq) && l<=i) {
                freq[s[l] - 'a']--;
                l++;
            }

            count += l;
        }

        return count;
    }
};