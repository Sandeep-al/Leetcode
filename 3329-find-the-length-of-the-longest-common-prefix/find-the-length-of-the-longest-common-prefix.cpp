class Solution {
public:
    int len(int x) {
        int ans = 0;
        while (x != 0) {
            ans += 1;
            x = x / 10;
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> mpp;
        for (auto& it : arr1) {
            int x = it;
            while (x != 0) {
                mpp.insert(x);
                x = x / 10;
            }
        }
        int maxi = 0;
        for (auto& it : arr2) {
            int x = it;
            while (x != 0) {
                if (mpp.count(x)) {
                    maxi = max(maxi, len(x));
                }
                x = x / 10;
            }
        }

        return maxi;
    }
};