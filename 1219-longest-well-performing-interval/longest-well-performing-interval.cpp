class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i]=prefix[i - 1] + ((hours[i - 1] > 8) ? 1 : -1);
        }

        unordered_map<int, int> mpp;
        int maxi=0;
        for (int i = 1; i <= n; i++) {
            int curr = prefix[i];

            if (curr > 0) {
                maxi = max(maxi, i);
            } else if (mpp.find(curr - 1) != mpp.end()) {
                maxi = max(maxi, i - mpp[curr - 1]);
            }
            if (mpp.find(curr) == mpp.end()) {
                mpp[curr] = i;
            }
        }

        return maxi;
    }
};