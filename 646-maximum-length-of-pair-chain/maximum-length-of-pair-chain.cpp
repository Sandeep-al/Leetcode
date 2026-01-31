class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int currEnd = INT_MIN;
        int ans = 0;

        for (auto& p : pairs) {
            if (p[0] > currEnd) { // strictly >
                ans++;
                currEnd = p[1];
            }
        }

        return ans;
    }
};