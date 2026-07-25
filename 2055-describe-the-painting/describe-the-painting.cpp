class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> mpp;

        for (auto& it : segments) {
            mpp[it[0]] += it[2];
            mpp[it[1]] -= it[2];
        }

        long long prefix = 0;
        vector<vector<long long>> ans;
        for (auto it = mpp.begin(); it != mpp.end(); it++) {
            auto nxt = next(it);
            if (nxt == mpp.end()) {
                break;
            }

            prefix += it->second;

            int curr = it->first;
            int end = (nxt->first);
            if (prefix > 0) {
                ans.push_back({curr, end, prefix});
            }
        }

        return ans;
    }
};