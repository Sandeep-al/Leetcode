class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mpp;
        int count = 0;
        int curr = 1;
        int assigned = 0;
        for (auto& it : word) {
            if (mpp.find(it) != mpp.end()) {
                count += mpp[it];
            } else {
                mpp[it] = curr;
                count += curr;
                assigned++;
            }

            if (assigned == 8) {
                curr++;
                assigned = 0;
            }
        }

        return count;
    }
};