class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        if (nums.size() == 1)
            return {-1, -1};

        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        int x1 = INT_MAX;
        int y1 = INT_MAX;
        for (auto it : mpp) {
            for (auto jt : mpp) {
                if (it.first < jt.first && it.second != jt.second) {
                    if (it.first < x1) {
                        x1 = it.first;
                        y1 = jt.first;
                    } else if (it.first == x1) {
                        if (jt.first < y1) {
                            y1 = jt.first;
                        }
                    }
                }
            }
        }
        if(x1==INT_MAX && y1==INT_MAX) return {-1,-1};
        return {x1, y1};
    }
};