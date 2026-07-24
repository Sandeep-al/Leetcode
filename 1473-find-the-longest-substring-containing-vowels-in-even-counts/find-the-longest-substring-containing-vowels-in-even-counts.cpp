class Solution {
public:
    int findTheLongestSubstring(string s) {

        int n = s.size();
        vector<int> prefix(n, 0);
        char init = s[0];
        unordered_map<char, int> mapping;
        mapping['a'] = 4;
        mapping['e'] = 3;
        mapping['i'] = 2;
        mapping['o'] = 1;
        mapping['u'] = 0;

        if (mapping.find(s[0]) != mapping.end()) {
            prefix[0] = 0 ^ (1 << mapping[s[0]]);
        }
        for (int i = 1; i < n; i++) {
            if (mapping.find(s[i]) == mapping.end()) {
                prefix[i] = prefix[i - 1];
            } else {
                prefix[i] = prefix[i - 1] ^ (1 << mapping[s[i]]);
            }
        }

        unordered_map<int, int> mpp2;
        mpp2[0] = -1;
        int maxi = 0;
        for (int r = 0; r < n; r++) {
            int curr = prefix[r];

            if (mpp2.find(curr) != mpp2.end()) {
                maxi = max(maxi, r - mpp2[curr]);
            }

            if (mpp2.find(curr) == mpp2.end()) {
                mpp2[curr] = r;
            }
        }

        return maxi;
    }
};