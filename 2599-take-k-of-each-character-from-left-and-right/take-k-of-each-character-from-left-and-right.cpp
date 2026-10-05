class Solution {
public:
    int k;
    int it_is_valid(vector<int>& freq, vector<int>& total) {
        for (int i = 0; i < 3; i++) {
            if (freq[i] > total[i] - k) {
                return 0;
            }
        }

        return 1;
    }
    int takeCharacters(string s, int k) {
        this->k=k;
        int n = s.size();
        vector<int> total(3, 0);
        for (int i = 0; i < s.size(); i++) {
            total[s[i] - 'a']++;
        }

        for (int i = 0; i < 3; i++) {
            if (total[i] < k) {
                return -1;
            }
        }

        vector<int> freq(3, 0);
        int l = 0;
        int maxi = 0;

        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;

            while (!it_is_valid(freq, total)) {
                freq[s[l] - 'a']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return n - maxi;
    }
};