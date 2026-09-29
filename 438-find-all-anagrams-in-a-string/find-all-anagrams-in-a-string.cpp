class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq1[26];
        for (int i = 0; i < p.size(); i++) {
            freq1[p[i] - 'a']++;
        }
        int k = p.size();
        int freq[26];
        vector<int> ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {

            freq[s[i] - 'a']++;

            if (i >= k) {
                freq[s[i - k] - 'a']--;
            }

            if (i >= k - 1) {
                int possible = 1;
                for (int i = 0; i < 26; i++) {
                    if (freq1[i] != freq[i]) {
                        possible = 0;
                        break;
                    }
                }

                if (possible) {
                    ans.push_back(i-k+1);
                }
            }
        }

        return ans;
    }
};