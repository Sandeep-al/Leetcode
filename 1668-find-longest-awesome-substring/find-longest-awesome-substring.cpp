class Solution {
public:
    int longestAwesome(string s) {
       
        int n = s.size();
        vector<int> prefix(n, 0);

        prefix[0] = (1 << (s[0] - '0'));

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ (1 << (s[i] - '0'));
        }

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int maxi = 0;

        for (int r = 0; r < n; r++) {
            int curr = prefix[r];

            if (mpp.find(curr) != mpp.end()) {
                maxi = max(maxi, r - mpp[curr]);
            }

            for (int b = 0; b < 10; b++) {
                int new_curr = curr ^ (1 << b);
                if (mpp.find(new_curr) != mpp.end()) {
                    maxi = max(maxi, r - mpp[new_curr]);
                }
            }

            if (mpp.find(curr) == mpp.end()) {
                mpp[curr] = r;
            }
        }

        return maxi;
    }
};